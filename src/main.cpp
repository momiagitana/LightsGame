#include <SFML/Graphics.hpp>

#include "Bfs.h"

// int main()
// {
//     auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

//     while (window.isOpen())
//     {
//         window.clear();
//         window.display();

//         if (auto event = sf::Event{}; window.waitEvent(event))
//         {
//             switch (event.type)
//             {
//             case sf::Event::Closed:
//                 window.close();
//                 break;
//             }
//         }
//     }
// }

int main()
{
    Graph g(9);

    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(5, 4); 
    g.addEdge(2, 6); 
    g.addEdge(2, 3); 
    g.addEdge(3, 5); 
    g.addEdge(6, 8); 
    g.addEdge(1, 7); 
    g.addEdge(8,7);

    g.removeEdge(0 , 1);
  
    g.BFS(0); 

    if(g.checkIfConnected())
      std::cout<<"all nodes are connected"<<std::endl;
    else
      std::cout<<"all nodes arent connected"<<std::endl;
    
  return 0;
}