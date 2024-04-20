//
// Created by Geena-Maria van Dijk on 4/14/24.
//

#include "Graph.h"
#include <queue>
#include <list>
#include <stack>


void Graph::InsertGraph(string line, unordered_set<string>& filler, unordered_set<string>& badWords)
{
    string word = "";
    string videoID = "";

    for(int i = 0; i <= line.size(); i++)
    {
        while (videoID.size() < 11)
        {
            videoID = videoID + line[i];
            i++;
        }
        if (!word.empty() && (line[i] == ' ' || line[i] == ':' || line[i] == '-'|| line[i] == '_' || line[i] == ',' || line[i] == ';' || line[i] == '.' || line[i] == '"'|| line[i] == '(' || line[i] == ')'|| line[i] == '!' || line[i] == '|' || line[i] == '\n' || i == line.size()))
        {
            if (filler.find(word)!= filler.end())
            {
                word = "";
                continue;
            }

            if(word.size()>2)
            {
                titleGraph[videoID].insert(word);
                if (!isBad[videoID])
                    isBadWord(videoID, word, badWords);
                graph[videoID];
                for (unordered_map<string , unordered_set <string> >:: iterator x = graph.begin(); x != graph.end(); x++)
                {
                    if (x->first.compare(videoID) == 0)
                        continue;

                    if(titleGraph[x->first].find(word) != titleGraph[x->first].end())
                        {
                            graph[videoID].insert(x->first);
                            graph[x->first].insert(videoID);
                        }
                }
            }
            word = "";
        }
        if (isalpha(line[i]))
        {
            line[i] = tolower(line[i]);
            word = word + line[i];
        }
    }
}

bool Graph::isConnectedBFS(string videoID)
{
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

bool Graph::isConnectedDFS(string videoID)
{
    //perform bfs
    unordered_set <string> visited;
    stack <string> s;

    visited.insert(videoID);
    s.push(videoID);

    while (!s.empty())
    {
        string u = s.top();

        //Check if video has a bad word
        if (isBad[u])
            return true;
        s.pop();
        unordered_set<string> neighbors = graph[u];
        for (unordered_set<string>::iterator it =  neighbors.begin(); it != neighbors.end(); it++ )
        {
            if(visited.count(*it) == 0)
            {
                visited.insert(*it);
                s.push(*it);
            }
        }
    }

    return false;
}

void Graph::isBadWord(string videoID, string word, unordered_set<string>& badWords)
{
    {
        if(badWords.find(word) != badWords.end())
        {
            isBad[videoID] = true;
            return;
        }

    }

    isBad[videoID] = false;

}
