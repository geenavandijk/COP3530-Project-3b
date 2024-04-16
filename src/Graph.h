//
// Created by Geena-Maria van Dijk on 4/14/24.
//
#pragma once
#ifndef COP3530_PROJECT_3_GRAPH_H
#define COP3530_PROJECT_3_GRAPH_H
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
using namespace std;

class Graph {
private:
    map<string , set <string> > graph;
    map<string, bool> isBad;
    map<string, set <string> > titleGraph;

public:
    void InsertGraph(string videoID, string title);
    //Returns true if videoID is connected to a bad video using BFS
    bool isConnectedBFS(string videoID);
    void hasBadWord(string videoID);
    Graph(){};

};


#endif //COP3530_PROJECT_3_GRAPH_H
