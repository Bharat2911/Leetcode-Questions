class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     
        queue<pair<int,int>>q;
        
        int fresh=0;
        
        //multisource bfs we will be doing here boss jii
        
        int row=grid.size();
        int col=grid[0].size();
        
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
        if(fresh==0)return 0;
        
        int count=0;
        
         int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        while(!q.empty())
        {
            int sz=q.size();
            
            count++;
            
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
                        
                        q.push({newi,newj});
                        
                        fresh--;
                        
                    }
                }
            }
            
        }
        if(fresh==0)return count-1;
        
        else return -1;
    }
};