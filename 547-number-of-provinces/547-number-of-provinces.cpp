class Solution {
public:
    void solve(int start,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[start]=1;
        for(auto itr:adj[start])
        {
            if(!vis[itr])
            {
                vis[itr]=1;
                solve(itr,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        
        //make the aj list 
        
        //count the components of the grpah using the dfs algo
        
        int n=grid.size();
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                solve(i,vis,adj);
            }
        }
        return count;
    }
};