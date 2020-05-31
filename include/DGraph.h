#pragma once
#include <DNode.h>
#include <list>
#include <iostream>


using lineOfNodes = std::vector <std::shared_ptr<DNode>>;
using matOfNodes = std::vector <lineOfNodes>;

class DGraph
{
private:

    lineOfNodes m_nodes;
    
    bool checkConnected() const;

public:

    void addNode(std::shared_ptr<DNode>);
    void handleClick(const sf::Event, const sf::Vector2f);
    void draw(sf::RenderWindow&);
    bool bfs();
    void removeLeg(const int, const int);
    void addLeg(const int, const int);
    int getAmountOfNodes() const;
    void spinEmRound();
    //void nextLevelAnimation(sf::RenderWindow&);

    DGraph(matOfNodes);
    DGraph();
    ~DGraph();
};


