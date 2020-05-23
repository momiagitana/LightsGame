
#include <DGraph.h>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(600, 600), "LIGHTS GAME");

    DNode n1({1,0,0,0,0,0}, sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    DNode n2({0,1,0,1,0,0}, sf::Vector2f(window.getSize().x/2+UNIT_SIZE*8, window.getSize().y/2));
    // DNode n3({1,1,1,1,0,0}, sf::Vector2f(window.getSize().x/2-UNIT_SIZE*8, window.getSize().y/2));
    n1.addNeighbour(&n2, 0);
    n2.addNeighbour(&n1, 3);

    DGraph graph;

    graph.addNode(&n1);
    graph.addNode(&n2);
    // graph.addNode(n3);

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
