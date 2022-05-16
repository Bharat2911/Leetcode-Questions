class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
         
        int row=grid.size();
        int col=grid[0].size();
        
        //0->opewn cell can move through them
        //1->closed cell cant move through them
        
        
        if(grid[0][0]==1)
        {
            return -1;
        }
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        q.push({0,0});//push the starting point
        vis[0][0]=1;
        
        int ans=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            ans++;
            
            while(sz--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                //all the possible eight directions
                
                 int dx[]={-1,-1,-1,0,1,1,1,0};
                 int dy[]={-1,0,1,1,1,0,-1,-1};
                
                for(int idx=0;idx<8;idx++)
                {
                    int newi=i+dx[idx];
                    int newj=j+dy[idx];
                    
                    //condition that once we reach end return the answer
                    if(i==row-1 and j==col-1)
                    {
                        return ans;
                    }
                    
                    if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]==0)
                    {
                        vis[newi][newj]=1;
                        q.push({newi,newj});
                        
                    }
                }
                
            }
        }
      return -1;
        
        
    
    }
};