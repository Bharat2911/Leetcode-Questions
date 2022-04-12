class Solution
{
    public:
        int count_of_neighbors(int i, int j, vector<vector < int>> &grid, int row, int col)
        {
            int count = 0;

            if (i + 1 >= 0 and i + 1 < row and j >= 0 and j < col and grid[i + 1][j] == 1) count++;	//down 
            if (i - 1 >= 0 and i - 1 < row and j >= 0 and j < col and grid[i - 1][j] == 1) count++;	//up
            if (i >= 0 and i < row and j - 1 >= 0 and j - 1 < col and grid[i][j - 1] == 1) count++;	//left
            if (i >= 0 and i < row and j + 1 >= 0 and j + 1 < col and grid[i][j + 1] == 1) count++;	//right
            if (i + 1 >= 0 and i + 1 < row and j + 1 >= 0 and j + 1 < col and grid[i + 1][j + 1] == 1) count++;
            if (i - 1 >= 0 and i - 1 < row and j - 1 >= 0 and j - 1 < col and grid[i - 1][j - 1] == 1) count++;
            if (i + 1 >= 0 and i + 1 < row and j - 1 >= 0 and j - 1 < col and grid[i + 1][j - 1] == 1) count++;
            if (i - 1 >= 0 and i - 1 < row and j + 1 >= 0 and j + 1 < col and grid[i - 1][j + 1] == 1) count++;

            return count;
        }
    void gameOfLife(vector<vector < int>> &board)
    {

       	//move in all the eight directon and count he no of live cells 
       	//then apply all the four given conditions 
       	//note we cant chage and count in the same matrix for that make the replica of given matrix and changes will 
       	//be done in the given matrix

        int row = board.size();
        int col = board[0].size();

        vector<vector < int>> grid = board;
       	//counting must be done from gird matrix and changes must be apply to board matrix

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int count = count_of_neighbors(i, j, grid, row, col);

                if (board[i][j] == 0)
                {
                    if (count == 3)
                    {
                        board[i][j] = 1;
                    }
                }
                else
                {
                    if (count < 2 || count > 3)
                    {
                        board[i][j] = 0;
                    }
                    else if (count == 2 || count == 3)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};