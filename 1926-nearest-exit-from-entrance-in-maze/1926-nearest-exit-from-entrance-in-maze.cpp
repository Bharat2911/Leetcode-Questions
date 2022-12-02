class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& e) {
        
        //approach ->using the bfs because we know that bfs give me the minimum steps
        
        int row=grid.size();
        int col=grid[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(row,vector<int>(col,0));
     
        
        q.push({e[0],e[1]});
        vis[e[0]][e[1]]=1;
        
        
        
        int ans=0;
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int idx=0;idx<4;idx++)
                {
                    int newi=i+dx[idx];
                    int newj=j+dy[idx];
                    
                    if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]=='.')
                    {
                        if(newi==0 || newi==row-1 || newj==0 || newj==col-1)
                        {
                            //i got the exit point
                            return ans+1;
                        }
                        vis[newi][newj]=1;
                        
                        q.push({newi,newj});
                    }
                }
            }
          
            ans++;
        }
        return -1;
    }
};