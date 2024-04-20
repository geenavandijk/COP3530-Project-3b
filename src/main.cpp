#include <iostream>
#include "Graph.h"
#include <fstream>

int main() {

    //set with meaningless/filler words
    unordered_set <string> filler;
    filler.insert("today");
    filler.insert ("this");
    filler.insert ("the");
    filler.insert ("that");
    filler.insert ("those");
    filler.insert ("these");
    filler.insert ("maybe");
    filler.insert ("them");
    filler.insert ("they");
    filler.insert ("you");
    filler.insert ("for");
    filler.insert ("alright");
    filler.insert ("every");
    filler.insert ("much");
    filler.insert ("real");
    filler.insert ("more");
    filler.insert ("less");
    filler.insert ("thing");
    filler.insert ("from");
    filler.insert ("and");
    filler.insert ("most");
    filler.insert ("how");
    filler.insert ("why");
    filler.insert ("what");
    filler.insert ("gonna");
    filler.insert ("went");
    filler.insert ("get");
    filler.insert ("let");
    filler.insert ("come");
    filler.insert ("when");
    filler.insert ("your");
    filler.insert ("here");
    filler.insert ("want");
    filler.insert ("does");
    filler.insert ("not");
    filler.insert ("with");
    filler.insert ("all");
    filler.insert ("top");
    filler.insert ("became");
    filler.insert ("new");
    filler.insert ("near");
    filler.insert ("side");
    filler.insert ("lost");
    filler.insert ("actually");
    filler.insert("amp");
    filler.insert("video");
    filler.insert("trailer");
    filler.insert ("hours");
    filler.insert("years");
    filler.insert("time");
    filler.insert("full");
    filler.insert("out");
    //words that have a lot of instances and may heavily influence the result but aren't that substantial
    filler.insert("color");
    filler.insert("game");
    filler.insert("blue");
    filler.insert("live");


    //set of bad words
    unordered_set<string> badWords;
    badWords.insert ("violence");
    badWords.insert ("sex");
    badWords.insert ("murder");
    badWords.insert ("gun");
    badWords.insert ("idiot");
    badWords.insert ("dumb");
    badWords.insert ("stupid");
    badWords.insert ("kill");
    badWords.insert("mafia");
    badWords.insert("felon");
    badWords.insert("danger");

    Graph graph;
    ifstream myDataFile;
    myDataFile.open("../yt-data.csv");
    string line;

   auto start = std::chrono::steady_clock::now();
    if (myDataFile.is_open())
    {
        getline(myDataFile,line);
        int i = 0;
        while(getline(myDataFile,line) && i <350)
        {
            if (!line.empty())
                graph.InsertGraph(line, filler, badWords);
            i++;
        }
    }
    else
        cout << "unable to open file" << endl;

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start);

    cout << "It took " << elapsed.count() << " milliseconds to load the graph" << endl << endl;

    myDataFile.close();

    //get user input for video to search

    string video_id = "c86t8hoVg8E";
//
    start = std::chrono::steady_clock::now();
    if(graph.isConnectedBFS(video_id))
        cout << "this video is connected to a bad video" << endl;
    else
        cout << "this video is NOT connected to a bad video"<< endl;
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start);
    cout << "It took " << elapsed.count() << " millisecond for isConnectedBFS to run" << endl << endl;

    start = std::chrono::steady_clock::now();
    if(graph.isConnectedDFS(video_id))
        cout << "this video is connected to a bad video" << endl;
    else
        cout << "this video is NOT connected to a bad video"<< endl;
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start);
    cout << "It took " << elapsed.count() << " millisecond for isConnectedDFS to run" << endl;
    return 0;
}
