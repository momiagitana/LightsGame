
#include <LevelBuilder.h>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(600, 600), "LIGHTS GAME");

    LevelBuilder level (1, window.getSize());
    DGraph graph =  level.build();

    while (window.isOpen())
    {
        window.clear();
        graph.draw(window);
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonReleased:
                
                auto mouseLoc = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                graph.handleClick(event, mouseLoc);

                break;
            }

        }
    }
}
