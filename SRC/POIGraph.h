#pragma once
#include "POIMap.h"

#include <vector>
#include <string>
using namespace std;

class POIGraph {
    public:
        POIGraph();
        void insertPOIs();
        void insertDistances();
        vector<string> BFS(int source);
        vector<string> BFS(int source, int dest);
        tuple<vector<string>> dijkstra(int source, int dest);
        tuple<vector<string>, double> middle(int source, int mid, int dest);
    private:
        string file_;
        POIMap map_;

};