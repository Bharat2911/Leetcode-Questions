class Solution {
public:
    void dfs(int start,unordered_map<int,bool>&vis,unordered_map<int,vector<int>>&adj,vector<int>&ans)
    {
        vis[start]=true;
        
        ans.push_back(start);
        
        for(auto itr:adj[start])
        {
            if(!vis[itr])
            {
                dfs(itr,vis,adj,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        unordered_map<int,bool>vis;
        
        vector<int>ans;
        
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        //start node vo hoga jo one time appear ho rha hai adj list me
        
        for(auto itr:adj)
        {
            if(itr.second.size()==1)
            {
                int start=itr.first;
                
                dfs(start,vis,adj,ans);
                
                break;
            }
        }
        
        return ans;
    }
};