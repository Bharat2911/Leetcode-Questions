class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col)
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
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[i][j]<=grid[newi][newj])
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
        
        vector<vector<int>>vis_p(row,vector<int>(col,0));
        vector<vector<int>>vis_a(row,vector<int>(col,0));
        
        queue<pair<int,int>>q_p;
        queue<pair<int,int>>q_a;
        
        //fill both the queue
        
        
        //here we have more than one starting point for both the bfs call means we have to to multisource bfs
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || j==0)
                {
                    q_p.push({i,j});
                    vis_p[i][j]=1;
                    
                }
                if(i==row-1 || j==col-1)
                {
                    q_a.push({i,j});
                    vis_a[i][j]=1;
                }
            }
        }
        bfs(q_p,grid,vis_p,row,col);
        bfs(q_a,grid,vis_a,row,col);
        
        
        vector<vector<int>>ans;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(vis_p[i][j]==1 and vis_a[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};