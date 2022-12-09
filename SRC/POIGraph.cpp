#include "POIGraph.h"
#include <queue>
#include <string>

using namespace std;

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
