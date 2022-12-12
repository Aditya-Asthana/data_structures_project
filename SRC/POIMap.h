#pragma once

#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#include "Edge.h"

struct Node {
    int id;
    double latitude;
    double longitude;
    string name;
    unordered_map<int, Edge> destinations;
};

class POIMap {

    public:
        map<int, Node> interest_map;
        void insertNode(int id, string name, double lat, double lon);
        void insertEdge(int source, int dest, double dist);
        double findDistance(int source, int dest);

};