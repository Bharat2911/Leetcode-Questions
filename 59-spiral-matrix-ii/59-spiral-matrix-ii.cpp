class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {

           	//make an answer matrix
            vector<vector < int>> ans(n, vector<int> (n));

            int number = 1;
            int row1 = 0;
            int row2 = n - 1;

            int col1 = 0;
            int col2 = n - 1;

            while (number <= n *n)
            {
               	//now just apply the spiral traversal steps 
               	//itration in four directions

               	//left to right

                for (int i = col1; i <= col2; i++)
                {
                    ans[row1][i] = number++;
                }
                row1++;

               	//top to down
                for (int i = row1; i <= row2; i++)
                {
                    ans[i][col2] = number++;
                }
                col2--;

               	//right to left

                for (int i = col2; i >= col1; i--)
                {
                    ans[row2][i] = number++;
                }
                row2--;

               	//down to top

                for (int i = row2; i >= row1; i--)
                {
                    ans[i][col1] = number++;
                }
                col1++;
            }
            return ans;
        }
};