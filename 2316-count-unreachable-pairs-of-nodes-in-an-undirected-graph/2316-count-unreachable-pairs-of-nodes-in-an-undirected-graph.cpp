class Solution {
public:
    void solve(int start,vector<int>adj[],vector<int>&vis,vector<int>&v)
    {
        queue<int>q;
        q.push(start);
        vis[start]=1;
        int count=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            
            for(auto itr:adj[node])
            {
                if(!vis[itr])
                {
                    vis[itr]=1;
                    q.push(itr);
                }
            }
           
        }
         v.push_back(count);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        
        for(auto itr:edges)
        {
            int u=itr[0];
            int v=itr[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        int components=0;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                components++;
                solve(i,adj,vis,v);
            }
        }
        long long ans=0;
        long long pro;
        
        for(int i=0;i<v.size();i++)
        {
            pro=(long long)v[i]*(n-v[i]);
            
            ans+=pro;
        }
        if(components==1)return 0;
        else return ans/(long long)2;
    }
};