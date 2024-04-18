#include <iostream>
#include "Graph.h"
#include <fstream>

int main() {

    Graph graph;
    ifstream myDataFile;
    myDataFile.open("../text.csv");
    string line;
   // char delimiter = ',';
    if (myDataFile.is_open())
    {
        getline(myDataFile,line);
        int i = 0;
        while(getline(myDataFile,line))
        {
            graph.InsertGraph(line);
            i++;
        }
    }
    else
        cout << "unable to open file" << endl;

    myDataFile.close();

    if(graph.isConnectedBFS("W8y-Qo375fI"))
        cout << "this video is connected to a bad video";
    else
        cout << "this video is NOT connected to a bad video";
    return 0;
}
