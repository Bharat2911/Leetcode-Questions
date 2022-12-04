class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
          int len=roads.size();
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<len;i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        //apply bfs starting from node 1 and covering all node
        queue<pair<int,int>>q;
        
        vector<int>vis(n+1,0);
        
        q.push({1,INT_MAX});
        
        int ans=INT_MAX;
        
        while(!q.empty())
        {
            int node=q.front().first;
            
            int weight=q.front().second;
            
            q.pop();
            
            ans=min(ans,weight);
            
            vis[node]=1;
            
            for(auto itr:adj[node])
            {
                //since our adj list contains two things man
                int u=itr.first;
                int w=itr.second;
                
                if(!vis[u])
                {
                    q.push({u,w});
                    //node->weight
                }
            }
            
        }
        return ans;
    }
};