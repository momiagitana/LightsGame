#include <DGraph.h>

DGraph::DGraph(matOfNodes mat)
{
    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
            if (mat[row][col] != nullptr)
            {
                m_nodes.push_back(mat[row][col]);
                // mat[row][col]->setName(counter);
                // counter++;
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
}

void DGraph::draw(sf::RenderWindow& win)
{
    for (auto node : m_nodes)
        node->draw(win);
}