#include "POIGraph.h"
#include <queue>
#include <string>
#include <stack>

using namespace std;

void POIGraph::insertPOIs() {
    //read from data and use .insertNode(id, poi name, latitude, longitude)
}

void POIGraph::insertDistances() {
    //read from data and use .insertEdge(source id, end id, distance)
    //use findDistance(source id, dest id) to find the distance
}

vector<string> POIGraph::BFS(int source) {
    vector<bool> visited(20558);
    for (int i = 0; i < 20558; i++) {
        visited[i] = false;
    }

    queue<int> poiQueue;
    queue<int> searchQueue;
    poiQueue.push(source);
    searchQueue.push(source);

    int curr = source;
    while (!poiQueue.empty()) {
        curr = poiQueue.front();
        for (auto it = map_.interest_map[curr].destinations.begin(); it != map_.interest_map[curr].destinations.end(); it++) {
            if (!visited[it->first]) {
                searchQueue.push(it->first);
                poiQueue.push(it->first);
                visited[it->first] = true;
            }
        }
        poiQueue.pop();
    }

    vector<string> rv;
    while (!searchQueue.empty()) {
        int temp = searchQueue.front();
        rv.push_back(map_.interest_map[temp].name);
        searchQueue.pop();
    }
    return rv;
}

vector<string> POIGraph::BFS(int source, int dest) {
    vector<bool> visited(20558);
    for (int i = 0; i < 20558; i++) {
        visited[i] = false;
    }

    queue<int> poiQueue;
    vector<int> prev(20558);
    prev[source] = source;
    poiQueue.push(source);

    int curr = source;
    while (!poiQueue.empty()) {
        curr = poiQueue.front();
        for (auto it = map_.interest_map[curr].destinations.begin(); it != map_.interest_map[curr].destinations.end(); it++) {
            if (!visited[it->first]) {
                prev[it->first] = curr;
                poiQueue.push(it->first);
                visited[it->first] = true;
            }
        }
        if (curr == dest) {
            break;
        }
        poiQueue.pop();
    }

    if (curr != dest) {
        vector<string> empty;
        return empty;
    }

    stack<int> ids;
    while (curr != source) {
        ids.push(curr);
        curr = prev[curr];
    }
    ids.push(source);

    vector<string> rv;
    while (!ids.empty()) {
        int temp = ids.top();
        rv.push_back(map_.interest_map[temp].name);
        ids.pop();
    }

    return rv;
}

tuple<vector<string>, double> POIGraph::dijkstra(int source, int dest) {

    // @TODO: Insert Edge Cases

    vector<double> dist(20558);
    vector<int> prev(20558);
    vector<int> unvisited;

    for (auto it = map_.interest_map.begin(); it != map_.interest_map.end(); it++) {
        dist[it->first] = INT_MAX;
        unvisited.push_back(it->first);
    }

    prev[source] = source;
    dist[source] = 0;

    int curr;

    while (!unvisited.empty()) {
        double minDistance = INT_MAX;
        int minIndex;
        for (unsigned int i  = 0; i < unvisited.size(); i++) {
            if (dist[unvisited[i]] < minDistance) {
                minDistance = dist[unvisited[i]];
                minIndex = i;
            }
        }

        curr = unvisited[minIndex];
        unvisited.erase(unvisited.begin()+minIndex);

        if (curr == dest) {
            break;
        }

        for (auto it=map_.interest_map[curr].destinations.begin(); it != map_.interest_map[curr].destinations.end(); it++) {    //  search all departures from curr airport
            double temp = dist[curr] + (it->second).getDist();
            if (temp < dist[it->first]) {
                dist[it->first] = temp;
                prev[it->first] = curr;
            }
        }
    }

    if (curr != dest) {
        tuple<vector<string>,double> T;
        return T;
    }

    stack<int> idStack;
    while (curr != source) {
        idStack.push(curr);
        curr = prev[curr];
    }

    idStack.push(source);
    vector<string> path;

    while (!idStack.empty()) {
        int temp = idStack.top();
        path.push_back(map_.interest_map[temp].name);
        idStack.pop();
    }

    return tuple<vector<string>,double> (path, dist[dest]);
}

tuple<vector<string>, double> POIGraph::middle(int source, int mid, int dest) {
    tuple<vector<string>, double> first = dijkstra(source, mid);
    tuple<vector<string>, double> second = dijkstra(mid, dest);
    if (get<0>(first).empty() || get<0>(second).empty()) {
        tuple<vector<string>, double> empty;
        return empty;
    }

    vector<string> path = get<0>(first);
    path.insert(path.end(), get<0>(second).begin() + 1, get<0>(second).end());
    double dist = get<1>(first) + get<1>(second);
    tuple<vector<string>, double> rv(path, dist);
    return rv;
}
