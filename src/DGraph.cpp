#include <DGraph.h>

DGraph::DGraph(/* args */)
{
}

DGraph::~DGraph()
{   
}

void DGraph::addNode(DNode* newNode)
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