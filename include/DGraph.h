#pragma once
#include <DNode.h>

#include "Bfs.h"

using lineOfNodes = std::vector <std::shared_ptr<DNode>>;
using matOfNodes = std::vector <lineOfNodes>;

class DGraph
{
private:

    lineOfNodes m_nodes;

    //Bfs m_bfsChecker;
    

public:

    void addNode(std::shared_ptr<DNode>);
    void handleClick(sf::Event, sf::Vector2f);
    void draw(sf::RenderWindow&);
    DGraph(matOfNodes);
    ~DGraph();
};


