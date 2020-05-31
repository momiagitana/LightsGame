#include <Controller.h>

Controller::Controller(/* args */)
    :m_window (sf::VideoMode(600, 750), "LIGHTS GAME")
{
}
   
Controller::~Controller()
{

}

void Controller::next()
{
    Button next (sf::Vector2f(m_window.getSize().x-NEXT_SIZE, m_window.getSize().y-NEXT_SIZE));
    bool leave = false;
    while(!leave && m_window.isOpen())
    {
        m_window.clear();
        m_graph.draw(m_window);
        next.drawButton(m_window);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
                auto mouseLoc = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                if(next.clickOnMe(mouseLoc))
                    leave = true;;
            }
        }
    }
}

void Controller::run()
{
    while(m_levelNum <= MAX_LEVEL && m_window.isOpen())
    {
        m_graph = LevelBuilder(m_levelNum++, m_window.getSize()).build();
        bool wonLevel = false;

        while (m_window.isOpen())
        {
            m_window.clear();
            m_graph.draw(m_window);
            m_window.display();

            if(wonLevel)
            {
                next();
                break;
            }

            if (auto event = sf::Event{}; m_window.waitEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    m_window.close();
                    break;

                case sf::Event::MouseButtonReleased:
                    
                    auto mouseLoc = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                    m_graph.handleClick(event, mouseLoc);

                    if(m_graph.bfs())
                    {
                        wonLevel = true;
                        break;
                        
                    }
                }

            }
            
        }
    }
    won();
}


void Controller::won()
{
    sf::Texture text;
    text.loadFromFile("won.png");
    sf::Sprite won;
    won.setTexture(text);
    won.setOrigin(sf::Vector2f(won.getGlobalBounds().width/2,won. getGlobalBounds().height/2));
    won.setPosition(sf::Vector2f(m_window.getSize().x/2, m_window.getSize().y/2));

    m_window.clear();
    m_graph.draw(m_window);
    m_window.draw(won);
    m_window.display();

    while(m_window.isOpen())
    {
        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
                m_window.close();
                break;
            }
        }
    }
}