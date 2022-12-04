class Solution {
public:
    int minScore(int n, vector<vector<int>>& edges) {
        
         int x=edges.size();
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<x;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>vis(n+1,0);
        
        queue<vector<int>>q;
        
        q.push({1,INT_MAX});
        
        int ans=INT_MAX;
        
        while(!q.empty())
        {
            auto top=q.front();
            
            q.pop();
            
            ans=min(ans,top[1]);
            
            vis[top[0]]=1; 
            
            for(auto itr:adj[top[0]])
            {
                if(!vis[itr.first])
                {
                    q.push({itr.first,itr.second});
                }
            }
        }
        return ans;
        
    }
};