class Solution
{
    public:
        int countSquares(vector<vector < int>> &matrix)
        {

            int ans = 0;

            int row = matrix.size();

            int col = matrix[0].size();

            for (int i = 0; i < row; i++)
            {
                if (matrix[i][0] == 1)
                {
                    ans += 1;
                }
            }
            for (int i = 0; i < col; i++)
            {
                if (matrix[0][i] == 1)
                {
                    ans += 1;
                }
            }

            for (int i = 1; i < row; i++)
            {
                for (int j = 1; j < col; j++)
                {
                    if (matrix[i][j] != 0)	//because we need matrix having all one
                    {
                        matrix[i][j] = min({ matrix[i - 1][j],
                            matrix[i][j - 1],
                            matrix[i - 1][j - 1] }) + 1;
                        ans += matrix[i][j];
                    }
                }
            }
            if(matrix[0][0]==1)return ans-1;
            return ans;
        }
};