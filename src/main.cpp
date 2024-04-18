#include <iostream>
#include "Graph.h"
#include <fstream>

int main() {
    time_t start, end;
    Graph graph;
    ifstream myDataFile;
    myDataFile.open("../yt-data.csv");
    string line;
   // char delimiter = ',';
   time (&start);
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

    time(&end);
    double time_taken = double (end - start);
    cout << "It took " << time_taken << " seconds to load the graph" << endl << endl;

    myDataFile.close();

    time(&start);
    if(graph.isConnectedBFS("W8y-Qo375fI"))
        cout << "this video is connected to a bad video" << endl;
    else
        cout << "this video is NOT connected to a bad video"<< endl;
    time(&end);
    time_taken = double (end - start);
    cout << "It took " << time_taken << " second for isConnectedBFS to run" << endl << endl;

    time(&start);
    if(graph.isConnectedDFS("W8y-Qo375fI"))
        cout << "this video is connected to a bad video" << endl;
    else
        cout << "this video is NOT connected to a bad video"<< endl;
    time(&end);
    time_taken = double (end - start);
    cout << "It took " << time_taken << " second for isConnectedDFS to run" << endl;
    return 0;
}
