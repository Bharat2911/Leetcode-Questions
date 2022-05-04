class Solution {
public:
    void solve(int i,vector<int>adj[],vector<int>&vis)
    {
        vis[i]=1;
        
        for(auto itr:adj[i])
        {
            if(!vis[itr])
            {
                vis[itr]=1;
                solve(itr,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edge) {
        
        //make the graph 
        //do the traversal count the component 
        //ans is count-1
        int m=edge.size();
        
        if(m<n-1)return -1;
        
        vector<int>adj[n];
        
        vector<int>vis(n,0);
        
        for(int i=0;i<edge.size();i++)
        {
            int u=edge[i][0];
            int v=edge[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                solve(i,adj,vis);
            }
        }
        return count-1;
        
    }
};