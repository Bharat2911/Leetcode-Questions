class Solution {
public:
    //approach ->count the components and the elemnts in each component using bfs/dfs
    //then simply count the possible pairs
    void bfs(int start,vector<int>adj[],vector<int>&vis,int n,vector<int>&v)
    {
        queue<int>q;
        q.push(start);
        vis[start]=1;
        int count=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;//counting the elements in each components
            
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
        vector<int>v;
        
        for(auto itr:edges)
        {
            int u=itr[0];
            int v=itr[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int components=0;
        
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                components++;
                bfs(i,adj,vis,n,v);
            }
        }
        long long int ans=0;
        long long int pro;
        
        
        
        for(int i=0;i<v.size();i++)
        {
             pro=(long long int)v[i]*(n-v[i]);
            ans+=pro;
        }
        if(components==1)return 0;
        
        return ans/(long long int)2;
    }
};