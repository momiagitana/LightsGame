#include <LevelBuilder.h>


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(600, 750), "LIGHTS GAME");
<<<<<<< HEAD
    auto levelNum = 4;

    
    while(levelNum <= 5)
=======
    auto levelNum = 1;
   
    while(levelNum <= 3)
>>>>>>> d212caa73ece426f83ea1083e0518eff5e252752
    {
        LevelBuilder level (levelNum++, window.getSize());
        DGraph graph =  level.build();

        bool wonLevel = false;

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

                    if(graph.bfs())
                    {
                        wonLevel = true;
                        break;
                        
                    }
                }

            }
            
            if(wonLevel)
            {
                graph.printMessage(levelNum);
                //use a clock and display NEXT LEVEL!
                break;
            }
        }
        if(wonLevel && levelNum > 3)
            graph.wonGame();
    }
    
}

