class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
         vector<pair<int,double>>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            double w=succProb[i];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<double>dist(n,INT_MIN);
        
        priority_queue<pair<double,int>>pq;
        //->dist,node
        
        dist[start]=1;
        pq.push({1,start});
        
        while(!pq.empty())
        {
            double d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            for(auto itr:adj[node])
            {
                int u=itr.first;
                double w=itr.second;
                
                if(dist[u]<dist[node]*w)
                {
                    dist[u]=dist[node]*w;
                    
                    pq.push({dist[u],u});
                }
            }
        }
        if(dist[end]==INT_MIN)return 0;
        return dist[end];
    }
};