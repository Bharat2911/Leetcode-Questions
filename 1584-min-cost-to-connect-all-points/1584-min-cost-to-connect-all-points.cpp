class Solution
{
    public:
        int minCostConnectPoints(vector<vector < int>> &points)
        {

           	//step no one make the adj list 
           	//stroing the dist between the nodes and the nodes
            int n=points.size();
            
            vector<pair<int, int>> adj[n];
            int wt;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {

                    wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({ j, wt });
                    adj[j].push_back({ i,wt });
                }
            }
            //now simply apply the prisms algo (minimum sappning tree algo)
            
            vector<int>vis(n+1,0);
            
            //making the min heap (as use in prisms algo)
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
             pq.push({0,0});
        
            int ans=0;
            
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            
            ans+=dist;
            
            for(auto &itr:adj[node])
            {
                int next_node=itr.first;
                int weight=itr.second;
                
                if(!vis[next_node])
                {
                    
                    pq.push({weight,next_node});
                }
            }
        }
        
        
        return ans;
        }
};