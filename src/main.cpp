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
        while(getline(myDataFile,line) && i <337)
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

    string video_id;
    int selection;
    int bfs,dfs;

    cout << "Lets see if we can link a popular kids YouTube video to a video that is NOT kid friendly." << endl << endl;
    cout << "Please make your selection out of the following popular videos: (type the number value, -1 to terminate) " << endl;
    cout << "1. The Lion King Official Trailer\n2. Baby Shark Dance \n3. Twinkle, Twinkle, Little Star\n4. Bluey and Bingo DIY Paint Your Own Figurines! Crafts for Kids\n5. Blues Clues and You Kitchen Setup for Picnic! Mail Time" << endl;
    cin >> selection;
    while (selection != -1)
    {
        switch(selection) {
            case 1:
                video_id = "7TavVZMewpY";
                break;
            case 2:
                video_id = "XqZsoesa55w";
                break;
            case 3:
                video_id = "7Reju_WYT4Y";
                break;
            case 4:
                video_id = "G0n-WOrAUFw";
                break;
            case 5:
                video_id = "NygWzfBR1vs";
                break;
            default:
                video_id = "7TavVZMewpY";
                cout << "Not a valid selection, defaulting to 1." << endl;

        }
        start = std::chrono::steady_clock::now();
        if (graph.isConnectedBFS(video_id))
            cout << "this video is connected to a bad video" << endl;
        else
            cout << "this video is NOT connected to a bad video" << endl;
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        bfs =  elapsed.count();
        cout << "It took " << bfs << " millisecond for isConnectedBFS to run" << endl << endl;

        start = std::chrono::steady_clock::now();
        if (graph.isConnectedDFS(video_id))
            cout << "this video is connected to a bad video" << endl;
        else
            cout << "this video is NOT connected to a bad video" << endl;
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        dfs =  elapsed.count();
        cout << "It took " << dfs << " millisecond for isConnectedDFS to run" << endl << endl;

        if (dfs == bfs)
            cout << "DFS and BFS took the same amount of time!" << endl;
        else if (dfs > bfs)
            cout << "DFS was faster!" << endl;
        else
            cout << "BFS was faster!" << endl;

        cout << "Please make another selection or type -1 to exit." << endl;
        cin >> selection;
    }

    cout << "Thank you and Go Fvck yrsf!"<<endl;
    return 0;
}
