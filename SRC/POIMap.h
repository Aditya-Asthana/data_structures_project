#pragma once

#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#include "Edge.h"

struct Node {
    double latitude;
    double longitude;
    string name;
    unordered_map<string, Edge> destinations;
};

class POIMap {

    public:
        map<string, Node> interest_map;
        void insertNode(string name, double lat, double lon);
        void insertEdge(string source, string dest, double dist);

    private:
        double findDistance(string source, string dest);

};