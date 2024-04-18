#include <iostream>
#include "Graph.h"
#include <fstream>

int main() {

    Graph graph;
    ifstream myDataFile;
    myDataFile.open("../yt-data.csv");
    string line;
   // char delimiter = ',';
   auto start = std::chrono::steady_clock::now();
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

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start);

    cout << "It took " << elapsed.count() << " milliseconds to load the graph" << endl << endl;

    myDataFile.close();

    start = std::chrono::steady_clock::now();
    if(graph.isConnectedBFS("W8y-Qo375fI"))
        cout << "this video is connected to a bad video" << endl;
    else
        cout << "this video is NOT connected to a bad video"<< endl;
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start);
    cout << "It took " << elapsed.count() << " millisecond for isConnectedBFS to run" << endl << endl;

    start = std::chrono::steady_clock::now();
    if(graph.isConnectedDFS("W8y-Qo375fI"))
        cout << "this video is connected to a bad video" << endl;
    else
        cout << "this video is NOT connected to a bad video"<< endl;
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start);
    cout << "It took " << elapsed.count() << " millisecond for isConnectedDFS to run" << endl;
    return 0;
}
