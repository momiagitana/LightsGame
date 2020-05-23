#include <DNode.h>


DNode::DNode(std::vector<bool> legs, sf::Vector2f loc)
    :m_legs (legs), m_loc (loc)
{
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
    
 
    win.draw(circle);

    drawEdges(win, circle);

}

sf::CircleShape DNode::makeCircle() const
{
    sf::CircleShape circle(CIRCLE_SIZE);

    circle.setPointCount(60);
    circle.setPosition(m_loc);
    circle.setOrigin(circle.getGlobalBounds().width/2, circle.getGlobalBounds().height/2);
    
    return circle;
}

void DNode::drawEdges(sf::RenderWindow& win, const sf::CircleShape& circle) const
{
    sf::RectangleShape edge;
    edge.setFillColor(sf::Color::Red);
    edge.setSize(sf::Vector2f(30.0f, 2.0f));
    
    for (int i = 0; i < m_legs.size(); i++)
    {
        if (m_legs[i])
        {
            edge.setPosition(circle.getTransform().transformPoint(circle.getPoint(i*10+14)));
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
    std::rotate(m_legs.begin(), m_legs.begin()+1, m_legs.end());
}

void DNode::shiftL()
{
    std::rotate(m_legs.begin(), m_legs.begin()+1, m_legs.end());
}