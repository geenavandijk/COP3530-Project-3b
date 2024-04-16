#include <iostream>
#include "Graph.cpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Graph graph;
    graph.InsertGraph("000001", "vevo joji glimpse music\"");
    graph.hasBadWord("000001");
    graph.InsertGraph("000002", "vevo rihanna guns dance");
    graph.hasBadWord("000002");
    if(graph.isConnectedBFS("000001"))
        cout << "this video is connected to a bad video";
    return 0;
}
