
// void Bfs::BFS(int s)
// {
//     std::list<int> q;

//     for(auto i : m_visited) 
//         i = false;

//     m_visited[s] = true;
//     q.push_back(s);

//     while (!q.empty())
//     {
//         s = q.front();
//         q.pop_front();

//         for(auto i : m_edge[s])
//             if(!m_visited[i])
//             {
//                 m_visited[i] = true;
//                 q.push_back(i);
//             }
        
//     }
// }