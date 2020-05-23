#include <DNode.h>

void DNode::draw(sf::RenderWindow& win) const
{
    sf::CircleShape circle;

    circle.setRadius(1);
    circle.setOrigin(m_loc);

    if(m_on)
        circle.setFillColor(sf::Color::White);
    else
        circle.setFillColor(sf::Color::Blue);
    
 
    win.draw(circle);

    drawEdges(win);

    

}

void DNode::drawEdges(sf::RenderWindow& win) const
{
    
    
}