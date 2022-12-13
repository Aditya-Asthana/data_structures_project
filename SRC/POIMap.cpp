#include "POIMap.h"
#include <math.h>
#include "Edge.h"

void POIMap::insertNode(int id, string name, double lat, double lon) { //inserts a node on the groph
    Node POI;
    POI.id = id;
    POI.name = name;
    POI.latitude = lat;
    POI.longitude = lon;
    interest_map.insert(pair<int, Node>(id, POI));
}

void POIMap::insertEdge(int source, int dest, double dist) { //inserts an edge on teh grpah between two nodes
    Edge POI(source, dest, dist);
    if (interest_map[source].destinations.find(dest) == interest_map[source].destinations.end()) {
        interest_map[source].destinations.insert(pair<int, Edge>(dest, POI));
    }
}

double POIMap::findDistance(int source, int dest) { //finds the distance between two nodes using their coordinates
    double sLat = interest_map[source].latitude;
    double sLong = interest_map[source].longitude;
    double dLat = interest_map[dest].latitude;
    double dLong = interest_map[dest].longitude;

    double radius = 6371000;
    double one_phi = sLat * M_PI/180;
    double two_phi = dLat * M_PI/180;
    double delta_phi = (dLat - sLat) * M_PI/180;
    double delta_lambda = (dLong - sLong) * M_PI/180;

    double a = (sin(delta_phi/2) * sin(delta_phi/2)) + cos(one_phi) * cos(two_phi) * (sin(delta_lambda/2) * sin(delta_lambda/2));
    double c = 2 * atan2(sqrt(a), sqrt((1 - a)));
    double d = radius * c;

    return d/1000; // returns distance in km
}

