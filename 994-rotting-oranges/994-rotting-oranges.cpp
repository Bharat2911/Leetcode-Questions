class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        queue<pair<int,int>>q;
        
        int fresh=0;
        int time=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)fresh++;
                
                else if(grid[i][j]==2)
                {
                    q.push({i,j});//multisource bfs steps bubbs
                    
                }
            }
        }
        if(fresh==0)return 0;//is intially fresh is already zero
        
        int dx[4] = {1,0,-1,0};   //{-1,0}->LEFT, {1,0}->RIGHT, {0,-1}->UP, {0,1}->DOWN
         int dy[4] = {0,-1,0,1};
        
        
        while(!q.empty() and fresh>0)
        {
            int sz=q.size();
            
            time++;
            
            while(sz--)
            {
                int i=q.front().first;
                int j=q.front().second;
                
                q.pop();
                
                for(int idx=0;idx<4;idx++)
                {
                    int newi=i+dx[idx];
                    int newj=j+dy[idx];
                    
                    if(newi>=0 and newj>=0 and newi<row and newj<col and grid[newi][newj]==1)
                    {
                        fresh--;//now fresh converted to rotten na baacha
                        grid[newi][newj]=2;
                        
                        q.push({newi,newj});
                        
                    }
                }
            }
        }
        if(fresh==0)return time;
        return -1;
    }
};