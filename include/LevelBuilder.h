#pragma once
#include <DGraph.h>

using lineOfNodes = std::vector <std::shared_ptr<DNode>>;
using matOfNodes = std::vector <lineOfNodes>;

class LevelBuilder
{
private:
    int m_midRow;

    int m_cols;
    int m_rows;

    std::vector<int> m_sizes;
    float m_unitx;

    int m_nodeWidth;
    int m_nodeHeight;

    int m_topPad;

    void nullOrNode(matOfNodes&, int, int);
    void setPotentialNeighbours(matOfNodes&, int, int);

public:
    LevelBuilder(int, sf::Vector2u);
    ~LevelBuilder();

    DGraph build();
};

