class Solution {
public:
    bool is_cycle(vector<int>adj[],int n)
    {
        vector<int>indegree(n,0);
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(auto itr:adj[i])
            {
                indegree[itr]++;
            }
        }
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            count++;
            
            for(auto itr:adj[node])
            {
                indegree[itr]--;
                
                if(indegree[itr]==0)
                {
                    q.push(itr);
                }
            }

          }
        if(count==n)return false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
     
        //approch ->check cycle in the directed grapg if present the cycle return false else true
        
        vector<int>adj[n];
        
        for(auto itr:pre)
        {
            int u=itr[0];
            int v=itr[1];
            
            adj[u].push_back(v);
        }
        
        if(is_cycle(adj,n))
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
};