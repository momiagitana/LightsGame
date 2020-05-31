#include <DGraph.h>
//#include <unistd.h>

DGraph::DGraph()
{
}

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

void DGraph::removeLeg(const int node, const int leg)
{
    m_nodes[node]->takeLeg(leg);
}

void DGraph::addLeg(const int node, const int leg)
{
    m_nodes[node]->addLeg(leg);
}

void DGraph::spinEmRound()
{
    int times;

    for(auto& node : m_nodes)
    {
        times = rand() % LEGS; 
        while(times--)
            node->shiftL();
    }

}


int DGraph::getAmountOfNodes() const
{
    return m_nodes.size();
}

void DGraph::addNode(std::shared_ptr<DNode> newNode)
{
    m_nodes.push_back(newNode);
}

void DGraph::handleClick(const sf::Event click, const sf::Vector2f mouseLoc)
{
    for (auto& node : m_nodes)
        node->handleClick(click, mouseLoc);

    bfs();

}

void DGraph::draw(sf::RenderWindow& win)
{
    for (auto node : m_nodes)
        node->draw(win);
}

bool DGraph::bfs()
{
    //getting the center node
    int source = (m_nodes.size() - 1) / 2;

    std::list<int> q;

    for(auto i : m_nodes) 
        i->setStatus(false);

    m_nodes[source]->setStatus(true);

    q.push_back(source);

    while (!q.empty())
    {
        source = q.front();
        q.pop_front();

        for(auto i = 0 ; i < m_nodes[source]->vecNeighboursSize() ; i++)
        {
            auto currNeighour = m_nodes[source]->getCurrNeighbour(i);

            if(!(m_nodes[currNeighour]->getStatus()))
            {
                m_nodes[currNeighour]->setStatus(true);
                q.push_back(m_nodes[currNeighour]->getName());
            }
        }
    }

    return checkConnected();
}


bool DGraph::checkConnected() const
{
    for(auto i : m_nodes)
    {
        if(!i->getStatus())
        return false;
    }

    return true;
}

