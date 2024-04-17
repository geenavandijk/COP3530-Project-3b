#include <iostream>
#include "Graph.cpp"
#include <fstream>

int main() {

    Graph graph;
    ifstream myDataFile;
    myDataFile.open("text.csv");
    string videoID, titleString;
    string line;
   // char delimiter = ',';
    if (myDataFile.is_open())
    {
        getline(myDataFile,line);
        while(getline(myDataFile,line))
        {
            for(int i = 0; i < line.size(); i++)
            {
                while (videoID.size() < 11)
                {
                    while (line[i] == '"' || line[i] == ' ')
                        i++;
                    videoID = videoID + line[i];
                    i++;
                }
                if (line[i] == '"')
                    i++;
                   titleString = titleString + line[i];
            }

            cout << videoID << " and " << titleString << endl;
            videoID ="";
            titleString="";
        }
    }
    else
        cout << "unable to open file" << endl;

    myDataFile.close();


    graph.InsertGraph("000001", "vevo joji glimpse music\"");
    //graph.hasBadWord("000001");
    graph.InsertGraph("000002", "vevo rihanna guns dance");
    //graph.hasBadWord("000002");
    if(graph.isConnectedBFS("000001"))
        cout << "this video is connected to a bad video";
    return 0;
}
