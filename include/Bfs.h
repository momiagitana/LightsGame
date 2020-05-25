#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph 
{
public:

    Graph(int);

    void BFS(int s) ;
    void addEdge(int , int );
    bool checkIfConnected();
    void removeEdge(int, int);

private:

    std::vector< vector<int> > m_edge;
    std::vector<bool> m_visited;
};