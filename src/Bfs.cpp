#include "Bfs.h"

Bfs::Bfs(const int graphSize) 
{
    m_edge.resize(graphSize);
    m_visited.resize(graphSize);
}

void Bfs::addEdge(int src, int dest) 
{ 
    m_edge[src].push_back(dest);
} 

void Bfs::removeEdge(int src, int dst)
{
    for(auto i = m_edge[src].begin() ; i != m_edge[src].end(); i++)
            if(*i == dst)
                m_edge[src].erase(i);
    
}  

void Bfs::BFS(int s)
{
    std::list<int> q;

    for(auto i : m_visited) 
        i = false;

    m_visited[s] = true;
    q.push_back(s);

    while (!q.empty())
    {
        s = q.front();
        q.pop_front();

        for(auto i : m_edge[s])
            if(!m_visited[i])
            {
                m_visited[i] = true;
                q.push_back(i);
            }
        
    }
}

bool Bfs::checkIfConnected()
{
    for(auto i : m_visited)
        if(!i)
            return false;
            
    return true;
}