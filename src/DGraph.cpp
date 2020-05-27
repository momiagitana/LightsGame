#include <DGraph.h>

DGraph::DGraph(matOfNodes mat)
{
    auto counter = 0;

    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
            if (mat[row][col] != nullptr)
            {
                m_nodes.push_back(mat[row][col]);

                mat[row][col]->setName(counter);
                counter++;
            }

    for (auto& i : m_nodes)
    {
        i->checkTouches();
    }

}

DGraph::~DGraph()
{   
}

void DGraph::addNode(std::shared_ptr<DNode> newNode)
{
    m_nodes.push_back(newNode);
}

void DGraph::handleClick(sf::Event click, sf::Vector2f mouseLoc)
{
    for (auto& node : m_nodes)
        node->handleClick(click, mouseLoc);

    bfs((m_nodes.size() + 1)/2);

//need to decide what to do with this
   // checkConnected();

}

void DGraph::draw(sf::RenderWindow& win)
{
    for (auto node : m_nodes)
        node->draw(win);
}

void DGraph::bfs(int source)
{
    std::list<int> q;

    for(auto i : m_nodes) 
        i->setStatus(false);

//starting source off as true
    m_nodes[source]->setStatus(true);

    q.push_back(source);

    while (!q.empty())
    {
        source = q.front();
        q.pop_front();

        for(auto i = 0 ; i < m_nodes[source]->vecSize() ; i++)
        {
            auto currNeighour = m_nodes[source]->getCurrNeighbour(i);

            if(!(m_nodes[currNeighour]->getStatus()))
            {
                m_nodes[currNeighour]->setStatus(true);
                q.push_back(m_nodes[currNeighour]->getName());
            }
        }
    }
}


bool DGraph::checkConnected()
{
    for(auto i : m_nodes)
    {
        if(!i->getStatus())
        return false;
    }

    return true;
}