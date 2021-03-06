#include <LevelBuilder.h>
#include <math.h>
#include <time.h>


LevelBuilder::LevelBuilder(const int level, const sf::Vector2u winSize)
{
    srand (time(NULL));

    m_midRow = MID_ROW_BASE + (level - 1)*2;

    m_cols = m_midRow * 2 - 1;
    m_rows = (m_midRow - FIRST_ROW) * 2 + 1;


    m_unitx = ((winSize.x)/(m_midRow*2));
    
    m_nodeWidth = m_unitx*2;
    m_nodeHeight = m_nodeWidth * (sqrt(3)/2);

    m_topPad = (winSize.y - m_nodeHeight * (m_rows-1)) /2;


    for (int size = FIRST_ROW; size <= m_midRow; size ++)
        m_sizes.push_back(size);
    m_sizes.insert(m_sizes.end(), m_sizes.rbegin()+1, m_sizes.rend());
}

LevelBuilder::~LevelBuilder()
{
}

DGraph LevelBuilder::build()
{
    matOfNodes mat;
    mat.resize(m_rows, lineOfNodes(m_cols));

    
    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
            nullOrNode(mat,row,col);

    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
            if (mat[row][col] != nullptr)
                setPotentialNeighbours(mat, row, col);

    
    DGraph graph(mat);
    
    randomizeLevel(graph);

    return graph;

}

void LevelBuilder::randomizeLevel(DGraph& graph) const
{
    int node;
    int leg;

    while(graph.bfs())
    {
        node = rand() % graph.getAmountOfNodes();
        leg = rand() % LEGS; 
        graph.removeLeg(node, leg);
    }
    graph.addLeg(node, leg);

    removeMaxLegs(graph);

    graph.spinEmRound();

    graph.bfs();
    
}

void LevelBuilder::removeMaxLegs(DGraph& graph) const
{
    int leg;
    for (auto i = 0; i < graph.getAmountOfNodes(); i++)
    {
        bool legs[LEGS] = {0, 0, 0, 0, 0, 0};
        while(!checkedEveryLeg(legs))
        { 
			leg = rand() % LEGS;
            while(legs[leg])
                leg = rand() % LEGS;
            legs[leg] = 1;
            
            graph.removeLeg(i, leg);
            if (!graph.bfs())
                graph.addLeg(i, leg);
        }
    }
}

bool LevelBuilder::checkedEveryLeg(bool legs[]) const
{
    for (auto i = 0; i < LEGS; i++)
        if (legs[i] == 0)
            return false;
    return true;
}

void LevelBuilder::setPotentialNeighbours(matOfNodes& mat, const int row, const int col)
{
    
    std::vector<bool> legs;
    for (int i = 0; i < 6; i++)
    {
        int nRow = row+neigbDiff[i][0];
        int nCol = col+neigbDiff[i][1];
        if (nRow >= 0 && nRow < m_rows && nCol >= 0 && nCol <m_cols && mat[nRow][nCol] != nullptr)
        {
            mat[row][col]->addNeighbour(mat[row+neigbDiff[i][0]][col+neigbDiff[i][1]], i);
            legs.push_back(1);
        }
        else
            legs.push_back(0);
        
    }
    mat[row][col]->initLegs(legs);
}

void LevelBuilder::nullOrNode(matOfNodes & mat, const int row, const int col)
{
 
    int firstInRow = m_midRow - m_sizes[row];

    auto loc = sf::Vector2f((m_nodeWidth/2)+(m_unitx)*col, m_topPad + m_nodeHeight * row);
    
    
    if (col >= firstInRow && col < m_cols - firstInRow  && (((col - firstInRow) % 2) == 0))
        mat[row][col] = std::make_shared<DNode>(loc, m_unitx);
    else
        mat[row][col] = nullptr;

    
}
