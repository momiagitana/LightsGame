#include <LevelBuilder.h>
#include <math.h>


LevelBuilder::LevelBuilder(int level, sf::Vector2u winSize)
{
    m_midRow = MID_ROW_BASE + (level - 1)*2;
    m_width = m_midRow * 2 + 1;
    m_height = (m_midRow - FIRST_ROW) * 2 + 3;


    m_unitx = ((winSize.x - 10 )/((m_width-1)*2));
    

    m_sizes.push_back(0);
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
    mat.resize(m_height, lineOfNodes(m_width));

    
    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
            nullOrNode(mat,row,col);

    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
            if (mat[row][col] != nullptr)
                setPotentialNeighbours(mat, row, col);

    
    return DGraph(mat);

}

void LevelBuilder::setPotentialNeighbours(matOfNodes& mat, int row, int col)
{
    int neigbDiff [6][2]=  {{0, 2}, {1, 1}, {1,-1}, {0,-2}, {-1,-1}, {-1,1}}; //move to consts
    
    std::vector<bool> legs;
    for (int i = 0; i < 6; i++)
    {
        int nRow = row+neigbDiff[i][0];
        int nCol = col+neigbDiff[i][1];
        if (nRow >= 0 && nRow < m_height && nCol >= 0 && nCol <m_width && mat[nRow][nCol] != nullptr)
        {
            mat[row][col]->addNeighbour(mat[row+neigbDiff[i][0]][col+neigbDiff[i][1]], i);
            legs.push_back(1);
        }
        else
            legs.push_back(0);
        
    }
    mat[row][col]->initLegs(legs);
}

void LevelBuilder::nullOrNode(matOfNodes & mat, int row, int col)
{
    if (row == 0 || row == m_height-1 || col == 0 || col == m_width-1)
    {
        mat[row][col] = nullptr;
        return;
    }
    


    int firstInRow = m_midRow - m_sizes[row] + 1;

    int nodeWidth = m_unitx*4;
    int nodeHeight = nodeWidth * (sqrt(3)/2);

    auto loc = sf::Vector2f((nodeWidth/2)*col+9, nodeHeight * row);
    
    
    if (col >= firstInRow && col < m_width - firstInRow  && (((col - firstInRow) % 2) == 0))
        mat[row][col] = std::make_shared<DNode>(loc, m_unitx);
    else
        mat[row][col] = nullptr;

    
}

//  [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
//  [ 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 ]
//  [ 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0 ]
//  [ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ]
//  [ 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0 ]
//  [ 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 ]
//  [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
//