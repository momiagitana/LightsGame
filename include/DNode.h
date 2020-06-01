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
    int m_name;


    bool contains(const sf::Vector2f) const;
    void drawEdges(sf::RenderWindow&, const sf::CircleShape&) const;
    sf::CircleShape makeCircle() const;
    bool notMyNeighbour(const int) const;

public:

    void shiftL();
    void shiftR();
    void checkTouches();
    void draw(sf::RenderWindow&) const;
    void handleClick(const sf::Event, const sf::Vector2f);
    void addNeighbour(const std::shared_ptr<DNode>, const int);
    bool isTouching(DNode*);
    void initLegs(const std::vector<bool>);
    void setName(const int);
    int  getName() const;
    void removeNeighbour(const int toRemove);
    void takeLeg(const int);
    void addLeg(const int);
    void setStatus(bool);
    bool getStatus() const;
    int getCurrNeighbour(const int);
    int vecNeighboursSize() const;

    
    DNode(sf::Vector2f, float);
    virtual ~DNode();
};
