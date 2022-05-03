class Solution {
public:
    int ans=0;
    
    void bfs(int i,int j,int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        queue<pair<int,int>>q;
        
        q.push({i,j});
        vis[i][j]=true;
        int count=1;
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=x+dx[idx];
                int newj=y+dy[idx];
                
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]==1)
                {
                    vis[newi][newj]=true;
                    count++;
                    q.push({newi,newj});
                }
            }
        }
        ans=max(ans,count);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        
        
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] and grid[i][j]==1 )
                {
                    
                    bfs(i,j,row,col,grid,vis);
                }
            }
        }
        return ans;
    }
};