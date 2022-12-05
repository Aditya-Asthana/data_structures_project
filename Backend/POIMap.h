#pragma once

#include <string>
#include <unordered_map>
#include <map>
using namespace std;

struct Node {
    double latitude;
    double longitude;
    string name;
    unordered_map<string, Node> destinations;
};

class POIMap {

    public:
        map<string, Node> interest_map;
        void insertNode();
        void insertEdge();

    private:
        double findDistance(string source, string dest);

};