#include <catch2/catch_test_macros.hpp>

#include "../SRC/POIGraph.h"
#include "../SRC/POIMap.h"
#include <vector>
#include <string>
using namespace std;

TEST_CASE("Check Number of Nodes", "weight=[5]") {
    POIGraph graph = POIGraph("../POIs/tests.csv");
    REQUIRE(graph.getMap().interest_map.size() == 19);
}

TEST_CASE("Check Number of Edges", "weight=[5]") {
    POIGraph graph = POIGraph("../POIs/tests.csv");
    int count = 0;
    for(const auto& [k, v] : graph.getMap().interest_map) {
        count += v.destinations.size();
    }
    REQUIRE(count == 180);
}

TEST_CASE("Check BFS one argument", "weight=[5]") {

    vector<string> test;
    test.push_back("1 ASTOR PLAZA");
    test.push_back("104 PRECINCT");
    test.push_back("102 ST BRIDGE OVR HAWTREE BASIN");
    test.push_back("1010 E 178 ST HOUSES");
    test.push_back("100% PLAYGROUND");
    test.push_back("100 QUINCY COMMUNITY GARDEN");
    test.push_back("10 STREET PEDESTRIAN");
    test.push_back("1 WORLD TRADE CENTER");
    test.push_back("1 PRECINCT");
    test.push_back("1 EAST RIVER PLACE");
    test.push_back("ALFRED E SMITH CAREER AND TECHNICAL EDUCATION HIGH SCHOOL");
    test.push_back("103 PRECINCT");
    test.push_back("102 PRECINCT");
    test.push_back("101 PRECINCT");
    test.push_back("100 ST DEPOT");
    test.push_back("100 PRECINCT");
    test.push_back("10 PRECINCT");
    test.push_back("1 WESTERN UNION INTERNATIONAL PLAZA");
    test.push_back("1 LEFRAK CITY PLAZA");
    test.push_back("1 ASTOR PLAZA");

    POIGraph graph = POIGraph("../POIs/tests.csv");
    vector<string> vect = graph.BFS(0);

    for (unsigned int i = 0; i < vect.size(); i++) {
        REQUIRE(vect[i] == test[i]);
    }

}

TEST_CASE("Check BFS two arguments", "weight=[5]") {
    vector<string> test;
    test.push_back("1 ASTOR PLAZA");
    test.push_back("104 PRECINCT");
    test.push_back("1 WESTERN UNION INTERNATIONAL PLAZA");

    POIGraph graph = POIGraph("../POIs/tests.csv");
    vector<string> vect = graph.BFS(0, 4);

    for (unsigned int i = 0; i < vect.size(); i++) {
        REQUIRE(vect[i] == test[i]);
    }
}

TEST_CASE("Check Djikstra", "weight=[5]") {
    POIGraph graph = POIGraph("../POIs/tests.csv");
    tuple<vector<string>, double> dj = graph.middle(0, 2, 5);
    vector<string> test;
    test.push_back("1 ASTOR PLAZA");
    test.push_back("1 EAST RIVER PLACE");
    test.push_back("1 LEFRAK CITY PLAZA");
    test.push_back("1 WORLD TRADE CENTER");
    for (unsigned long i = 0; i < get<0>(dj).size(); i++) {
        REQUIRE(test[i] == get<0>(dj)[i]);
    }    
}