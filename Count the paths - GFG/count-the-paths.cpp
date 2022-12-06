//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int start,vector<vector<int>>&adj,vector<int>paths,vector<vector<int>>&ans,int target)
    {
        paths.push_back(start);
        
        if(start==target)
        {
            ans.push_back(paths);
            
            return;
        }
        else
        {
            for(auto itr:adj[start])
            {
                dfs(itr,adj,paths,ans,target);
            }
        }
        paths.pop_back();//backtracking step
        
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<vector<int>>adj(n);
	    
	    for(auto itr:edges)
	    {
	        int u=itr[0];
	        int v=itr[1];
	        
	        adj[u].push_back(v);
	    }
	    
	    vector<int>paths;
	    vector<vector<int>>ans;
	    
	    dfs(s,adj,paths,ans,d);
	    
	    return ans.size();
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends