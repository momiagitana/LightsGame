#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <globals.h>

class DNode
{
private:
    std::vector <bool> m_legs;
    std::vector <DNode *> m_neighbours;

    sf::Vector2f m_loc;

    bool m_on = false;




public:

    void draw(sf::RenderWindow&) const;
    void drawEdges(sf::RenderWindow&, const sf::CircleShape&) const;
    bool contains(sf::Vector2f) const;
    sf::CircleShape makeCircle() const;
    
    void shiftL();
    void shiftR();


    DNode(std::vector<bool>, sf::Vector2f);
    ~DNode();
};
