#pragma once
#include <DNode.h>


class DGraph
{
private:
    std::vector <DNode*> m_nodes;
public:

    void addNode(DNode*);
    void handleClick(sf::Event, sf::Vector2f);
    void draw(sf::RenderWindow&);
    DGraph(/* args */);
    ~DGraph();
};


