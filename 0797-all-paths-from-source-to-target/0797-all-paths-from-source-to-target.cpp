class Solution {
public:
    void solve(int start,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>path,int &target)
    {
        path.push_back(start);
        
        if(start==target)
        {
            ans.push_back(path);
            return;
        }
        else
        {
            for(auto itr:adj[start])
            {
                solve(itr,adj,ans,path,target);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        //make the adj list
        int n=graph.size();
        
        vector<vector<int>>adj(n);
        int target=n-1;
        int start=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>>ans;
        vector<int>path;
        
        solve(start,adj,ans,path,target);
        
        return ans;
    }
};