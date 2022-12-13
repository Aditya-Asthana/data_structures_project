#pragma once
#include "POIMap.h"

#include <vector>
#include <string>
using namespace std;

class POIGraph {
    public:
        POIGraph(const string& poiFile);
        void insertPOIs();
        void insertDistances();
        vector<string> BFS(int source);
        vector<string> BFS(int source, int dest);
        tuple<vector<string>, double> dijkstra(int source, int dest);
        tuple<vector<string>, double> middle(int source, int mid, int dest);
        vector<string> parseLine(const string& line);
        vector<string> parseLoc(const string& line);
        POIMap getMap() {return map_;}
        int Centrality (string poi) {

    private:
        string file_;
        POIMap map_;

};