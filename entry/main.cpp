#include "../SRC/POIGraph.h"
#include "../SRC/POIMap.h"

#include <iostream>

int main() {
    POIGraph graph = POIGraph("../POIs/POI_Parsed.csv");
    for(const auto& [k, v] : graph.getMap().interest_map) {
        std::cout << v.latitude << std::endl;
    }
    return 0;
}