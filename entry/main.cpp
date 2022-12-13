#include "../SRC/POIGraph.h"
#include "../SRC/POIMap.h"
#include <vector>
#include <string>
using namespace std;

#include <iostream>

int main() {
    POIGraph graph = POIGraph("../POIs/tests.csv");
    std::cout << "Number of Nodes : " << graph.getMap().interest_map.size() << std::endl;
    int count = 0;
    for(const auto& [k, v] : graph.getMap().interest_map) {
        count += v.destinations.size();
    }
    std::cout << "Number of Edges: " << count << std::endl;

    vector<string> vect = graph.BFS(0);
    std::cout << "Source BFS" << std::endl;

    for (string s : vect) {
        std:: cout << s << std::endl;
    }

    std::cout << "Source + Dest BFS" << std::endl;
    vector<string> vect2 = graph.BFS(0, 4);

    std::cout << vect2.size() << std::endl;

    for (string s : vect2) {
        std::cout << s << std::endl;
    }

    // for (unsigned i = 0; i < vect2.size(); i++) {
    //     std::cout << vect2[i] << std::endl;
    // }

    std::cout << "Dijkstra" << std::endl;

    tuple<vector<string>, double> dj = graph.middle(0, 2, 5);
    for (string s : get<0>(dj)) {
        std::cout << s << std::endl;
    }    
    std::cout << get<1>(dj) << std::endl;

    std::cout << "Centrality" << std::endl;
    int check = graph.Centrality("1 ASTOR PLAZA");
    std::cout << check << std::endl;
}