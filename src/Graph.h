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
    void InsertGraph(string inputLine, unordered_set<string>& filler, unordered_set<string>& badWords);
    //Returns true if videoID is connected to a bad video using BFS
    bool isConnectedBFS(string videoID);
    //Returns true if videoID is connected to a bad video using DFS
    bool isConnectedDFS(string videoID);
    void isBadWord(string videoID, string word, unordered_set<string>& badWords);
    Graph(){};

};


#endif //COP3530_PROJECT_3_GRAPH_H
