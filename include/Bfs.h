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


private:

    std::vector< std::vector<int> > m_edge;
    std::vector<bool> m_visited;
};