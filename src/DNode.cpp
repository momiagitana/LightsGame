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

void DNode::initLegs(std::vector<bool> legs)
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


bool DNode::contains(sf::Vector2f loc) const
{
    if(makeCircle().getGlobalBounds().contains(loc))
        return true;
    
    return false;
}

void DNode::shiftR()
{
    std::rotate(m_legs.begin(),m_legs.end()-1,m_legs.end());
}

void DNode::shiftL()
{
    std::rotate(m_legs.begin(), m_legs.begin()+1, m_legs.end());
}

void DNode::handleClick(sf::Event click, sf::Vector2f mouseLoc)
{
    if (contains(mouseLoc))
    {
        if (click.mouseButton.button == sf::Mouse::Right)
            shiftR();
        if (click.mouseButton.button == sf::Mouse::Left)
            shiftL();

        checkTouches();
    }


}

void DNode::addNeighbour(std::shared_ptr<DNode> newNei, int index)
{
    m_potentialNeighbours[index] = newNei;
}

void DNode::checkTouches()
{
    for (int i = 0; i < m_legs.size(); i++)
        if (m_legs[i] && m_potentialNeighbours[i] != nullptr) //check if can take nullptr
            if(m_potentialNeighbours[i]->isTouching(this))//
                m_on = true; //add to list
            // else
            // {
            //     //take it off from list
            // }
            
}

bool DNode::isTouching(DNode* calledMe)
{
    for(int i = 0; i < m_potentialNeighbours.size(); i++)
        if (m_potentialNeighbours[i].get() == calledMe && m_legs[i])
        {
            m_on = true;
            return true;
        }
    
    return false;
}

void DNode::takeLeg(int leg)
{
    m_legs[leg] = 0;
}