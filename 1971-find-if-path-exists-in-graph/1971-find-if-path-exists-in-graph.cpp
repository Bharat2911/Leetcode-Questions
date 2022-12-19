class Solution {
public:
    bool solve(int start,vector<int>adj[],vector<int>&vis,int target)
    {
        queue<int>q;
        q.push(start);
        vis[start]=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            if(node==target)
            {
                return true;
            }
            
            for(auto itr:adj[node])
            {
                if(!vis[itr])
                {
                    vis[itr]=1;
                    q.push(itr);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        
        //approach if source and destination is in same component
        
        vector<int>adj[n];
        
        vector<int>vis(n,0);
        
        for(auto itr:edges)
        {
            int u=itr[0];
            int v=itr[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return solve(source,adj,vis,dest);
    }
};