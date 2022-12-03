class Solution {
public:
    void solve(vector<vector<int>>&grid,vector<vector<int>>&vis,queue<pair<int,int>>&q,int row,int col)
    {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=i+dx[idx];
                int newj=j+dy[idx];
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]>=grid[i][j])
                {
                    vis[newi][newj]=1;
                    q.push({newi,newj});
                }
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>p_vis(row,vector<int>(col,0));
        
        vector<vector<int>>a_vis(row,vector<int>(col,0));
        
        queue<pair<int,int>>p_q;
        
        queue<pair<int,int>>a_q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || j==0)
                {
                    p_q.push({i,j});
                    
                    p_vis[i][j]=1;
                }
                
                if(i==row-1 || j==col-1)
                {
                    a_q.push({i,j});
                    
                    a_vis[i][j]=1;
                }
            }
        }
        solve(grid,p_vis,p_q,row,col);
        solve(grid,a_vis,a_q,row,col);
        
        vector<vector<int>>ans;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(p_vis[i][j] and a_vis[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};