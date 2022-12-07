#pragma once

#include <vector>
#include <string>
using namespace std;

class POIGraph {
    public:
        POIGraph();
        void insertPOIs();
        vector<string> BFS(string source);
        vector<string> BFS(string source, string dest);
        tuple<vector<string>> dijkstra(string source, string dest);
    private:
        string file_;

};