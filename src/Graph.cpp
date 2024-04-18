//
// Created by Geena-Maria van Dijk on 4/14/24.
//

#include "Graph.h"
#include <queue>
#include <list>


void Graph::InsertGraph(string line)
{
    //graph[videoID];
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
    filler.push_back("of");
    filler.push_back("you");
    filler.push_back("is");
    filler.push_back("for");
    filler.push_back("in");

    string word = "";
    string videoID = "";

    for(int i = 0; i <= line.size(); i++)
    {
        while (videoID.size() < 11)
        {
            videoID = videoID + line[i];
            i++;
        }
        //-------------
        //graph[videoID];
        //----------------
        if (!word.empty() && (line[i] == ' ' || line[i] == ':' || line[i] == '-'|| line[i] == '_' || line[i] == ',' || line[i] == ';' || line[i] == '.' || line[i] == '"'|| line[i] == '(' || line[i] == ')'|| line[i] == '!' || line[i] == '|' || line[i] == '\n' || i == line.size()))
        {
            //temp.insert(word);
            int j;
            for (j = 0; j < filler.size(); j++)
            {
                if (word.compare(filler[j]) == 0)
                {
                    word = "";
                    continue;
                }
            }

            //if (!word.empty())
            {
                titleGraph[videoID].insert(word);
                if (!isBad[videoID])
                    isBadWord(videoID, word);
                graph[videoID];
                for (unordered_map<string , unordered_set <string> >:: iterator x = graph.begin(); x != graph.end(); x++)
                {
                    if (x->first.compare(videoID) == 0)
                        continue;

                    //use set.find ---

                    //for (unordered_set<string>::iterator it = titleGraph[videoID].begin(); it != titleGraph[videoID].end(); it++)
                    {
                        if(titleGraph[x->first].find(word) != titleGraph[x->first].end())
                        {
                            graph[videoID].insert(x->first);
                            graph[x->first].insert(videoID);
                            //break;
                        }

                    }
                }
                word = "";
            }
        }
        if (isalpha(line[i]))
        {
            line[i] = tolower(line[i]);
            word = word + line[i];
        }
    }

    //hasBadWord(videoID);

    //create edges :')
    /*for (unordered_map<string , unordered_set <string> >:: iterator x = graph.begin(); x != graph.end(); x++)
    {
        if (x->first.compare(videoID) == 0)
            continue;

        //use set.find ---

        for (unordered_set<string>:: iterator it1 = titleGraph[videoID].begin(); it1 !=  titleGraph[videoID].end(); it1++)
        {
            for (unordered_set<string>:: iterator it2 = titleGraph[x->first].begin(); it2 !=  titleGraph[x->first].end(); it2++)
            {

                if ((*it1).compare(*it2) == 0)
                {

                    graph[videoID].insert(x->first);
                    graph[x->first].insert(videoID);
                }
            }
        }

    }*/

}

bool Graph::isConnectedBFS(string videoID)
{
    //perform bfs
    unordered_set <string> visited;
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
        unordered_set<string> neighbors = graph[u];
        for (unordered_set<string>::iterator it =  neighbors.begin(); it != neighbors.end(); it++ )
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

void Graph::isBadWord(string videoID, string word)
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
        if(word.find(badWords[i]) != -1)
        {
            isBad[videoID] = true;
            return;
        }

    }

    isBad[videoID] = false;

}
