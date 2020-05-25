#pragma once
#include <DGraph.h>

using lineOfNodes = std::vector <std::shared_ptr<DNode>>;
using matOfNodes = std::vector <lineOfNodes>;

class LevelBuilder
{
private:
    int m_midRow;
    int m_width;
    int m_height;
    std::vector<int> m_sizes;
    float m_unitx;
    float m_unity;

    void nullOrNode(matOfNodes&, int, int);
    void setPotentialNeighbours(matOfNodes&, int, int);

public:
    LevelBuilder(int, sf::Vector2u);
    ~LevelBuilder();

    DGraph build();
};

