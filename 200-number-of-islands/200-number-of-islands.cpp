class Solution {
public:
    void dfs(int i,int j,int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        //base case
        //out of bound conditiojn
        if(i<0 || i>=row || j<0 || j>=col)
        {
            return;
        }
        else if(grid[i][j]=='0')
        {
            return;
        }
        
        if(!vis[i][j])
        {
            vis[i][j]=1;
            
            //send in all the dour direction so that  we get the one in that direction it automativcally marked visited
            dfs(i+1,j,row,col,grid,vis);
            dfs(i-1,j,row,col,grid,vis);
            dfs(i,j+1,row,col,grid,vis);
            dfs(i,j-1,row,col,grid,vis);
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        int count=0;
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    count++;
                    
                    dfs(i,j,row,col,grid,vis);
                    
                }
            }
        }
        return count;
    }
};