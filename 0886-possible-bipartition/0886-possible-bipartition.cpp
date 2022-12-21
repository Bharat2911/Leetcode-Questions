class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        
        //we have to make and undirected graph
       for(auto itr:edges)
       {
           int u=itr[0]-1;
           int v=itr[1]-1;
           
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
        
        vector<int>color(n,-1);
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=0;
            }
            
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                
                for(auto itr:adj[node])
                {
                    if(color[itr]==-1)
                    {
                        q.push(itr);
                        color[itr]=1-color[node];
                    }
                    else if(color[itr]==color[node])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};