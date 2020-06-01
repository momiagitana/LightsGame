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

    void nullOrNode(matOfNodes&, const int, const int);
    void setPotentialNeighbours(matOfNodes&, const int, const int);
    void randomizeLevel(DGraph&) const;
    void removeMaxLegs(DGraph&) const;
    bool checkedEveryLeg(bool legs[]) const;

public:
    LevelBuilder(const int, const sf::Vector2u);
    virtual ~LevelBuilder();

    DGraph build();
};

