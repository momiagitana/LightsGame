#include <DNode.h>
#include <iostream>


DNode::DNode(sf::Vector2f loc, float unit)
    :m_loc (loc), m_unit(unit)
{
    m_potentialNeighbours.resize(6);
    m_potentialNeighbours[0] = nullptr;
    m_potentialNeighbours[1] = nullptr;
    m_potentialNeighbours[2] = nullptr;
    m_potentialNeighbours[3] = nullptr; 
    m_potentialNeighbours[4] = nullptr;
    m_potentialNeighbours[5] = nullptr;
}

void DNode::initLegs(const std::vector<bool> legs)
{
    m_legs = legs;
}

DNode::~DNode()
{
}

void DNode::draw(sf::RenderWindow& win) const
{
    auto circle = makeCircle();

    if(m_on)
        circle.setFillColor(sf::Color::Yellow);
    else
        circle.setFillColor(sf::Color::White);
    
 
    drawEdges(win, circle);
    win.draw(circle);

}

sf::CircleShape DNode::makeCircle() const
{
    sf::CircleShape circle(CIRCLE_SIZE);

    circle.setPosition(m_loc);
    circle.setOrigin(circle.getGlobalBounds().width/2, circle.getGlobalBounds().height/2);
    
    return circle;
}

void DNode::drawEdges(sf::RenderWindow& win, const sf::CircleShape& circle) const
{

    sf::RectangleShape edge;
    edge.setFillColor(sf::Color::White);
    edge.setSize(sf::Vector2f(m_unit, 1.0f));
    edge.setOrigin(sf::Vector2f(0, 0.5));
    edge.setPosition(m_loc);

    
    for (int i = 0; i < m_legs.size(); i++)
    {
        if (m_legs[i])
        {
            edge.setRotation(i*60.0f);
            win.draw(edge);
        }
    }
}


bool DNode::contains(const sf::Vector2f loc) const 
{
    if(makeCircle().getGlobalBounds().contains(loc))
        return true;
    
    return false;
}

void DNode::shiftR()
{
    std::rotate(m_legs.begin(),m_legs.end()-1,m_legs.end());
    checkTouches();
}

void DNode::shiftL()
{
    std::rotate(m_legs.begin(), m_legs.begin()+1, m_legs.end());
    checkTouches();
}

void DNode::handleClick(const sf::Event click, const sf::Vector2f mouseLoc)
{
    if (contains(mouseLoc))
    {
        if (click.mouseButton.button == sf::Mouse::Right)
            shiftR();
        if (click.mouseButton.button == sf::Mouse::Left)
            shiftL();
    }
}

void DNode::addNeighbour(const std::shared_ptr<DNode> newNei, const int index)
{
    m_potentialNeighbours[index] = newNei;
}

void DNode::checkTouches()
{
    m_actualNeighbours.clear();

    for (int i = 0; i < m_legs.size(); i++)
        if (m_potentialNeighbours[i] != nullptr) //check if can take nullptr
        {
            if (m_legs[i] && m_potentialNeighbours[i]->isTouching(this))//
            {
                m_actualNeighbours.push_back(m_potentialNeighbours[i]->getName());
            }
            else //i dont have a leg pointing at him so im not his neighbour
            {
                m_potentialNeighbours[i]->removeNeighbour(getName());
            }

        }
}

bool DNode::isTouching(DNode* calledMe)           
{
    for(int i = 0; i < m_potentialNeighbours.size(); i++)
        if (m_potentialNeighbours[i].get() == calledMe && m_legs[i])
        {
            if(notMyNeighbour(calledMe->getName()))
                m_actualNeighbours.push_back(calledMe->getName());
            return true;
        }        

    return false;
}

bool DNode::notMyNeighbour(const int name) const
{
    for (auto& i : m_actualNeighbours)
        if (i == name)
            return false;
    
    return true;
}

void DNode::removeNeighbour(const int toRemove)
{
    for(auto i = 0; i < m_actualNeighbours.size(); i++)
        if(m_actualNeighbours[i] == toRemove)
            m_actualNeighbours.erase(m_actualNeighbours.begin() + i);
}

void DNode::setName(const int name)
{
    m_name = name;
}

int DNode::getName() const
{
    return m_name;
}

void DNode::takeLeg(const int leg)
{
    if (m_legs[leg])
    {
        m_legs[leg] = 0;
        checkTouches();
    }
}

void DNode::addLeg(const int leg)
{
    if(!m_legs[leg])
    {
        m_legs[leg] = 1;
        checkTouches();
    }
}

void DNode::setStatus(const bool status)
{
    m_on = status;
}

bool DNode::getStatus() const
{
    return m_on;
}

int DNode::getCurrNeighbour(const int pos)
{
    return m_actualNeighbours[pos];
}

int DNode::vecNeighboursSize() const
{
    return m_actualNeighbours.size();
}