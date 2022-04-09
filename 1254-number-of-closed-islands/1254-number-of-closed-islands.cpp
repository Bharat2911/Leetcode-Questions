class Solution {
public:
      void solve(int i,int j,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(i<0 || i>=row || j<0 ||j>=col)return;
        else if(grid[i][j]==1)return;
        
            grid[i][j]=1;
            //solve in four directions
            solve(i+1,j,row,col,grid,vis);
            solve(i,j+1,row,col,grid,vis);
            solve(i-1,j,row,col,grid,vis);
            solve(i,j-1,row,col,grid,vis);
        
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        
         int row=grid.size();
        int col=grid[0].size();
        int count=0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0 and (i == 0 || j == 0 || i ==  row-1 || j == col-1))
                {
                    solve(i,j,row,col,grid,vis);
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    
                    solve(i,j,row,col,grid,vis);
                }
            }
        }
        return count;
    }
};