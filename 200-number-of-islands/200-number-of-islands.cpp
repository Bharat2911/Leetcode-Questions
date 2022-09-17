class Solution {
public:
    void solve(int i,int j,int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=x+dx[idx];
                int newj=y+dy[idx];
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]=='1')
                {
                    vis[newi][newj]=1;
                    q.push({newi,newj});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        int count=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    count++;
                    
                    solve(i,j,row,col,grid,vis);
                }
                
            }
        }
        return count;
    }
};