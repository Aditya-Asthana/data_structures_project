#include "POIMap.h"
#include <math.h>

double POIMap::findDistance(string source, string dest) {
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

