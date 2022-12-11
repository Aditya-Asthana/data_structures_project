#pragma once

#include <string>
using namespace std;

class Edge {

    public:

        Edge(int source, int dest): dest_(dest), source_(source) {}
        Edge(int source, int dest, double dist): dest_(dest), source_(source), dist_(dist) {}

        int getSource() {return source_;}
        int getDest() {return dest_;}
        double getDist() {return dist_;}
        int getID() {return id_;}

        void setSource(int source) {source_ = source;}
        void setDest(int dest) {dest_ = dest;}
        void setDist(double dist) {dist_ = dist;}
        void setID(int id) {id_ = id;}

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
        int source_;
        int dest_;
        int id_;
        
};