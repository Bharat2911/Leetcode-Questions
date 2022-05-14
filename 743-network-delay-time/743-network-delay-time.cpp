class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //make he graph then apply dijstras akgo
        vector<vector<pair<int,int>>>adj(n);
        
        int m=times.size();
        
        for(int i=0;i<m;i++)
        {
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            
            adj[u].push_back({v,w});
        }
        int source=k-1;
        
        vector<int>distance(n,INT_MAX);
        
        //apply dijstras algo
        
        // min heap; -->dist,source
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,source});
        
        distance[source]=0;
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            
            for(auto itr:adj[node])
            {
                int v=itr.first;
                int w=itr.second;
                
                if(distance[node]+w<distance[v])
                {
                    distance[v]=distance[node]+w;
                    
                    pq.push({distance[v],v});
                }
            }
        }
        int ans=0;
        
        for(auto itr:distance)
        {
            if(itr==INT_MAX)return -1;
            else
            {
                ans=max(ans,itr);
            }
        }
        return ans;
    }
};