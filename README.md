<H1> COP3530 - Project 3 </h1>

# Team Details
- Team Name: Then there were 2
- Team Number: 22
- Team Members: Sean Hershkowitz & Geena-Maria van Dijk

# Proposed Project Details
## Project Title: 
Is there even a path to hell? (Not click bait, gone wrong)

## Problem:
How many videos can be connected to inappropriate content?

## Motivation:
YouTube, with over 2 billion global users, emphasizes that its platform isn't for children under 13 and suggests YouTube Kids for younger audiences, however, the percentage of young people using only YouTube Kids, as opposed to the broader site, is tiny. Recent consumer group surveys suggest that despite promises to police inappropriate content, YouTube continues to show violent imagery, drug references, racist language and sexually suggestive content that reaches children [1]. YouTube has a lot of influence on the youth and it is important to know the extent of that influence.

## Features:
For purposes of this project, the problem will be solved upon completion of a
“connectedness” algorithm’s run from the initial video, selected from a premade list of ten starting nodes, to whichever occurs first between the
first instance of a video flagged for inappropriate word, or the end of the data structure is reached.

## Data:
Data will be generated from YouTube, using publicly available API and video data [2]. The API will be fed a search criterion that is known and widely accepted as child safe, like “fun”, “meme”, or “learning”. From this initial criterion, the API will generate videos. We will then extract and store the first three adjectives and/or nouns as the title in our graph. Similar words in a title will be the criteria for an edge between videos. Each video’s title will be compared with a list of words that are widely considered inappropriate for child content. The data to be stored is each video’s ID, (reduced) title, as well as a possible indicator flag. Initial storage of this data is anticipated to be in an CSV file. The flag is false if the video is child friendly, or true if it is not.
videoID is a string consisting of case sensitive alphanumeric values
title is a vector of strings of size three
flag is a boolean

## Tools:
- C++: used to generate our data structure and algorithm.
- JavaScript: used to communicate with the YouTube API.
  
## Visuals:
We will use the command line interface. 

## Strategy:
- Data Structure: undirected Graph
- Algorithms for Consideration: Breadth-First Search (BFS), Depth-First Search (DFS) & If time allows us to do both, otherwise BFS

## Distribution of Responsibility and Roles:
- Data set retrieval - Sean
- First algorithm (BFS) - Geena / Sean
- Second algorithm (DFS) - Geena / Sean
- Data Structure (Graph) - Geena
- Main - Sean / Geena
- List of at least10 Inappropriate Terms - Geena
- List of filler words to be removed from title - Geena
- UI - Sean / Geena 


