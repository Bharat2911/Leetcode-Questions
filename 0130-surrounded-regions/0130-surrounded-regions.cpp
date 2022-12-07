class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<char>>&grid)
    {
        int row=grid.size();
        
        int col=grid[0].size();
        
        int dx[4]={0,1,0,-1};
        
        int dy[4]={1,0,-1,0};
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            grid[i][j]='#';
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=i+dx[idx];
                int newj=j+dy[idx];
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]=='O')
                {
                    vis[newi][newj]=1;
                    q.push({newi,newj});
                }
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        
        int row=board.size();
        int col=board[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || i==row-1 || j==0 || j==col-1)
                {
                    if(board[i][j]=='O')
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        bfs(q,vis,board);
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        return;
        
    }
};