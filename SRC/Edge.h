#pragma once

#include <string>
using namespace std;

class Edge {

    public:

        Edge(string source, string dest): dest_(dest), source_(source) {}
        Edge(string source, string dest, double dist): dest_(dest), source_(source), dist_(dist) {}

        string getSource() {return source_;}
        string getDest() {return dest_;}
        double getDist() {return dist_;}

        void setSource(string source) {source_ = source;}
        void setDest(string dest) {dest_ = dest;}
        void setDist(double dist) {dist_ = dist;}

        bool operator < (const Edge& other) const {
            return dist_ < other.dist_;
        }

        bool operator == (const Edge& other) const {
            if (source_  != other.source_) return false;
            if (dest_ != other.dest_) return false;
            return true;
        }

    private:
    
        double dist_;
        string source_;
        string dest_;
        
};