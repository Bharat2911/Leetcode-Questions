class Solution {
public:
    void dfs(int start,vector<int>&vis,vector<vector<int>>&grid,int n)
    {
        vis[start]=1;
        
        vector<int>adj;
        
        for(int i=0;i<n;i++)
        {
            int x=grid[start][i];
            if(x==1)
            {
                adj.push_back(i);
            }
        }
        for(auto itr:adj)
        {
            if(!vis[itr])
            {
                vis[itr]=1;
                dfs(itr,vis,grid,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        
        //make the adj list 
        //keep the count of component of graph 
        //this count will be our answer
        int n=grid.size();
        
        int count=0;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,vis,grid,n);
                
            }
        }
        return count;
    }
};