#pragma once

#include <LevelBuilder.h>
#include <button.h>

class Controller
{
private:
    int m_levelNum =1;
    DGraph m_graph;
    sf::RenderWindow m_window;
    

    void next();
    void won();
    
public:

    void run();
    Controller();
    ~Controller();
};
