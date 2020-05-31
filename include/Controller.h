#pragma once

#include <LevelBuilder.h>
#include <button.h>

class Controller
{
private:
    int m_levelNum = FIRST_LEVEL;
    DGraph m_graph;
    sf::RenderWindow m_window;
    

    void next();
    void won();
    
public:

    void run();
    Controller();
    ~Controller();
};
