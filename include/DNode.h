#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <globals.h>

class DNode
{
private:
    std::vector <bool> m_legs;
    std::vector <DNode*> m_neighbours;

    sf::Vector2f m_loc;

    bool m_on = false;


    void shiftL();
    void shiftR();
    bool contains(sf::Vector2f) const;
    bool isTouching(DNode*) const;
    void checkTouches();
    


public:

    void draw(sf::RenderWindow&) const;
    void drawEdges(sf::RenderWindow&, const sf::CircleShape&) const;
    sf::CircleShape makeCircle() const;
    void handleClick(sf::Event, sf::Vector2f);
    void addNeighbour(DNode*, int);
    bool isTouching(DNode*);
    


    DNode(std::vector<bool>, sf::Vector2f);
    ~DNode();
};
