//
// Created by Geena-Maria van Dijk on 4/14/24.
//
#pragma once
#ifndef COP3530_PROJECT_3_GRAPH_H
#define COP3530_PROJECT_3_GRAPH_H
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <utility>
using namespace std;

class Graph {
private:
    //no order necessary
    unordered_map<string , unordered_set <string> > graph;
    unordered_map<string, bool> isBad;
    unordered_map<string, unordered_set <string> > titleGraph;

public:
    //void InsertGraph(string videoID, string title);
    void InsertGraph(string line);
    //Returns true if videoID is connected to a bad video using BFS
    bool isConnectedBFS(string videoID);
    void isBadWord(string videoID, string word);
    Graph(){};

};


#endif //COP3530_PROJECT_3_GRAPH_H
