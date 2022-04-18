class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        
        int dp[row][col];
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=matrix[i][j]-48;//convert char to integer
                }
                else if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});//thsi is storing my edge of the square
                    
                }
                else
                {
                    dp[i][j]=0;
                }
                
                
                ans=max(ans,dp[i][j]);
                
            }
        }
        return ans*ans;
    }
};