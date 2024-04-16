//
// Created by Geena-Maria van Dijk on 4/14/24.
//

#include "Graph.h"
#include <queue>
#include <list>
#include <sstream>

//static const vector<string> badWords {"fuck", "shit", "sex", "penis", "drugs", "fight", "murder","gambling","blood","guns","idiot","dumb","stupid"};

void Graph::InsertGraph(string videoID, string title)
{
    graph[videoID];
    vector <string> filler;
    filler.push_back("this");
    filler.push_back("the");
    filler.push_back("an");
    filler.push_back("a");
    filler.push_back("that");
    filler.push_back("those");
    filler.push_back("these");
    filler.push_back("or");
    filler.push_back("maybe");
    filler.push_back("them");
    filler.push_back("they");
    filler.push_back("us");

    string word = "";

    for (auto x : title)
    //for (int i = 0; i <= title.size(); i++)
    {
        //x = title[i];
        ///fix this!! doesnt recognize end of string as space
        if (x == ' ' || x == ':' || x == '-'|| x == '_' || x == ',' || x == ';' || x == '.' || x == '"')
        {
            //temp.insert(word);
            int i;
            for (i = 0; i < filler.size(); i++)
            {
                if (word.compare(filler[i]) == 0)
                    word = "";
            }

            if (i = filler.size())
            {
                titleGraph[videoID].insert(word);

                word = "";
            }
        }
        else {
            word = word + x;
        }
    }

    hasBadWord(videoID);

    //create edges :')
    for (map<string , set <string> >:: iterator x = graph.begin(); x != graph.end(); x++)
    {
        if (x->first.compare(videoID) == 0)
            continue;

        for (set<string>:: iterator it1 = titleGraph[videoID].begin(); it1 !=  titleGraph[videoID].end(); it1++)
        {
            for (set<string>:: iterator it2 = titleGraph[x->first].begin(); it2 !=  titleGraph[x->first].end(); it2++)
            {

                if ((*it1).compare(*it2) == 0)
                {

                    graph[videoID].insert(x->first);
                    graph[x->first].insert(videoID);
                }
            }
        }

    }

}

bool Graph::isConnectedBFS(string videoID)
{
    //perform bfs
    set <string> visited;
    queue <string> q;

    visited.insert(videoID);
    q.push(videoID);

    while (!q.empty())
    {
        string u = q.front();

        //Check if video has a bad word
        if (isBad[u])
            return true;
        q.pop();
        set<string> neighbors = graph[u];
        for (set<string>::iterator it =  neighbors.begin(); it != neighbors.end(); it++ )
        {
            if(visited.count(*it) == 0)
            {
                visited.insert(*it);
                q.push(*it);
            }
        }
    }

    return false;
}

void Graph::hasBadWord(string videoID)
{
    vector<string> badWords;
    badWords.push_back("fuck");
    badWords.push_back("shit");
    badWords.push_back("sex");
    badWords.push_back("penis");
    badWords.push_back("drugs");
    badWords.push_back("murder");
    badWords.push_back("gambling");
    badWords.push_back("blood");
    badWords.push_back("guns");
    badWords.push_back("idiot");
    badWords.push_back("dumb");
    badWords.push_back("stupid");

    for (int i = 0; i < badWords.size();i++)
    {
        for (set<string>:: iterator it = titleGraph[videoID].begin(); it !=  titleGraph[videoID].end(); it++)
            if(badWords[i].compare(*it) == 0)
            {
                isBad[videoID] = true;
                return;
            }
    }

    isBad[videoID] = false;

}