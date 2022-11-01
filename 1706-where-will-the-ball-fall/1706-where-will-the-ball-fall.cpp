class Solution {
public:
    bool is_safe(vector<vector<int>>&grid,int i,int j,int row,int col)
    {
        if(i<0 || i>=row || j<0 || j>=col)return false;
        
        return true;
    }
    int dfs(vector<vector<int>>&grid,int i,int j,int row,int col)
    {
        //if i reach the ending row then i will get my answer
        if(i==row)return j;
        
        if(is_safe(grid,i,j,row,col))
        {
            if(grid[i][j]==1)
            {
                //out og bounf nahi hona chaiye and stuck condition nahi honi chaiye
                if(is_safe(grid,i,j+1,row,col) and grid[i][j+1]==1)
                {
                    return dfs(grid,i+1,j+1,row,col);
                }
            }
            else
            {
                if(is_safe(grid,i,j-1,row,col) and grid[i][j-1]==-1)
                {
                    return dfs(grid,i+1,j-1,row,col);
                }
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int row=grid.size();
        
        int col=grid[0].size();
        
        vector<int>ans(col,0);
        
        for(int i=0;i<col;i++)
        {
            ans[i]=dfs(grid,0,i,row,col);
        }
        
        return ans;
    }
};