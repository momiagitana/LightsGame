#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class DNode
{
private:
    std::vector <bool> m_legs;
    std::vector <DNode *> m_neighbours;

    sf::Vector2f m_loc;

    bool m_on = false;




public:

    void draw(sf::RenderWindow&) const;
    void drawEdges(sf::RenderWindow& win) const;
    bool contains() const;
    
    void shiftL();
    void shiftR();


    DNode(std::vector<bool>, sf::Vector2f);
    ~DNode();
};

DNode::DNode(std::vector<bool> legs, sf::Vector2f loc)
    :m_legs (legs), m_loc (loc)
{
}

DNode::~DNode()
{
}
