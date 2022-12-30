class Solution {
public:
    void solve(int start,vector<vector<int>>&ans,vector<int>paths,vector<vector<int>>&adj,int target)
    {
        paths.push_back(start);
        
        if(start==target)
        {
            ans.push_back(paths);
            return;
        }
        else
        {
            //itrate into adj list
            for(auto itr:adj[start])
            {
                solve(itr,ans,paths,adj,target);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>>ans;
        
        vector<int>paths;
        
        int target=n-1;
        
        int start=0;
        
        solve(start,ans,paths,adj,target);
        
        return ans;
    }
};