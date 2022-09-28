class Solution {
public:
    void bfs(int i,int j,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        vis[i][j]=1;
        q.push({i,j});
        grid[i][j]=0;
        
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
                    grid[newi][newj]=0;
                    vis[newi][newj]=1;
                    q.push({newi,newj});
                }
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        //we will be doing this using bfs
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               if(i==0 || j==0)
               {
                   if(!vis[i][j] and grid[i][j]==1)
                   {
                       bfs(i,j,row,col,grid,vis);
                   }
               }
                if(i==row-1 || j==col-1)
                {
                    if(!vis[i][j] and grid[i][j]==1)
                    {
                        bfs(i,j,row,col,grid,vis);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};