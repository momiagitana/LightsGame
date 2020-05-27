#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <globals.h>


class DNode
{
private:
    using lineOfNodes = std::vector <std::shared_ptr<DNode>>;

    std::vector <bool> m_legs;
    lineOfNodes m_potentialNeighbours;
    std::vector<int> m_actualNeighbours;

    float m_unit;
    sf::Vector2f m_loc;
    bool m_on = false;


    void shiftL();
    void shiftR();
    bool contains(sf::Vector2f) const;
    bool isTouching(std::shared_ptr<DNode>) const;
    void checkTouches();
    


public:

    void draw(sf::RenderWindow&) const;
    void drawEdges(sf::RenderWindow&, const sf::CircleShape&) const;
    sf::CircleShape makeCircle() const;
    void handleClick(sf::Event, sf::Vector2f);
    void addNeighbour(std::shared_ptr<DNode>, int);
    bool isTouching(DNode*);
    void initLegs(std::vector<bool>);
    void takeLeg(int);
    


    DNode(sf::Vector2f, float);
    ~DNode();
};
