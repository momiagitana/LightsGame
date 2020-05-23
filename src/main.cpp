
#include <DNode.h>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(600, 600), "LIGHTS GAME");

    DNode someNode({0,1,0,1,0,1}, sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    
   
    while (window.isOpen())
    {
        window.clear();
        someNode.draw(window);
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                
                auto mouseLocation = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                
                if (someNode.contains(mouseLocation))
                    someNode.shiftL();
            }
        }
    }
}
