class Solution {
public:
    //using dp memonization we will optimised it
    
    int solve(int starti,int startj,int row,int col,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        //base case
        if(starti<0 || starti>=row || startj<0 || startj>=col)
        {
            return 0;
        }
        //we have obstacle at value 1
        if(matrix[starti][startj]==1)
        {
            return 0;
        }
        //end case
        if(starti==row-1 and startj==col-1)
        {
            return 1;
        }
        
        if(dp[starti][startj]!=-1)
        {
            return dp[starti][startj];
            
        }
        int a=solve(starti+1,startj,row,col,matrix,dp);
        int b=solve(starti,startj+1,row,col,matrix,dp);
        
        return dp[starti][startj]=a+b;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        
        int starti=0;
        int startj=0;
        
        return solve(starti,startj,row,col,matrix,dp);
    }
};