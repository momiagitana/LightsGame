#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Bfs 
{
public:

    Bfs(int);

    void BFS(int s) ;
    void addEdge(int , int );
    bool checkIfConnected();
    void removeEdge(int, int);

private:

    std::vector< std::vector<int> > m_edge;
    std::vector<bool> m_visited;
};