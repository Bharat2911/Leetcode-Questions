class Solution {
public:
    void dfs(int start,vector<vector<int>>& grid,vector<int>&vis)
    {
        vis[start]=1;
          int n=grid.size();
        
        vector<int>adj;
        
        
            for(int j=0;j<n;j++)
            {
                int x=grid[start][j];
                
                if(x==1)
                {
                    adj.push_back(j);
                }
            }
    
        for(auto itr:adj)
        {
            if(!vis[itr])
            {
                vis[itr]=1;
                dfs(itr,grid,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        
        //->make the adj list
        // /->count the components of the grapg
        
        int n=grid.size();
        
//
        //by dfs we will count the component
        vector<int>vis(n,0);
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,grid,vis);
            }
        }
        return count;
    }
};