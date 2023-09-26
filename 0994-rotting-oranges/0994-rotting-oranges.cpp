class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row=grid.size();
        
        int col=grid[0].size();
        
        int fresh=0;
        
        int time=0;
        
        queue<pair<int,int>>q;
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
                
            }
        }
        if(fresh==0)
        {
            return 0;
        }
        while(!q.empty())
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
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and grid[newi][newj]==1)
                {
                    grid[newi][newj]=2;
                    fresh--;
                    
                    q.push({newi,newj});
                }
            }
            }
        }
        if(fresh==0)return time-1;
        
        else return -1;
    }
};