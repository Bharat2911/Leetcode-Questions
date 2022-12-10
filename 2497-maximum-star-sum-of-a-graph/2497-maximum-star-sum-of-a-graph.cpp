class Solution {
public:
    //implimentation me dikkat aa rhi hai question to samjh aagya hai
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        int n=vals.size();
        
        vector<vector<int>>adj(n);
        
        for(auto itr:edges)
        {
            int u=itr[0];
            int v=itr[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            
            //make min heap will apply concept of top k frequent elemnets
            priority_queue<int,vector<int>,greater<int>>pq;
            
            int sum=vals[i];
            
            for(auto itr:adj[i])
            {
                pq.push(vals[itr]);
                
                if(pq.size()>k)pq.pop();
            }
            while(!pq.empty())
            {
               if(pq.top()>0) sum+=pq.top();
                pq.pop();
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};