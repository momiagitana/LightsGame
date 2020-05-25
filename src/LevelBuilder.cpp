#include <LevelBuilder.h>


LevelBuilder::LevelBuilder(int level)
{
    m_midRow = MID_ROW_BASE + (level - 1)*2;
    m_width = m_midRow * 2 + 1;
    m_height = (m_midRow - FIRST_ROW) * 2 + 3;

    m_sizes.push_back(0);
    for (int size = FIRST_ROW; size <= m_midRow; size ++)
        m_sizes.push_back(size);
    m_sizes.insert(m_sizes.end(), m_sizes.rbegin()+1, m_sizes.rend());

    // std::vector<int> secondHalf(m_sizes);
    // std::reverse(secondHalf.begin(), secondHalf.end()-1);
}

LevelBuilder::~LevelBuilder()
{
}

DGraph LevelBuilder::build()
{
    std::vector <std::vector <std::shared_ptr<DNode>>> mat;
    mat.resize(m_height, std::vector <std::shared_ptr<DNode>>(m_width));

    int firstInRow;

    std::vector<bool> legsInit = {1,1,0,0,1,0};
    sf::Vector2f loc;
    
    for (int row = 0; row < mat.size(); row++)
        for (int col = 0; col < mat[0].size(); col++)
        {

            firstInRow = m_midRow - m_sizes[row] + 1;
            loc = sf::Vector2f(UNIT_SIZE*row, UNIT_SIZE*col);
            
            if (col >= firstInRow && firstInRow - col % 2 == 0)
                mat[row][col] = std::make_shared<DNode>(legsInit, loc);
            else
                mat[row][col] = nullptr;
        }
            //nullOrNode(mat,row,col);
    
    return DGraph(mat);

}

void LevelBuilder::nullOrNode(std::vector <std::vector <std::shared_ptr<DNode>>> & mat, int row, int col)
{
    if (row == 0 )
    {
        mat[row][col] = nullptr;
        return;
    }
    if (row == m_width-1)
    {
        mat[row][col] = nullptr;
        return;
    }
    if (col == 0)
    {
        mat[row][col] = nullptr;
        return;
    }
    if (col == m_height-1)
    {
        mat[row][col] = nullptr;
        return;
    }
    


    int firstInRow = m_midRow - m_sizes[row] + 1;

    std::vector<bool> legsInit = {1,1,0,0,1,0};
    auto loc = sf::Vector2f(UNIT_SIZE*row, UNIT_SIZE*col);
    
    
    if (col >= firstInRow && firstInRow - col % 2 == 0)
        mat[row][col] = std::make_shared<DNode>(legsInit, loc);
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