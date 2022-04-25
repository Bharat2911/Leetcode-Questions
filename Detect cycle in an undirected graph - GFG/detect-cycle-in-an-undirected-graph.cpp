// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycle(int start,vector<int>adj[],vector<bool>&vis,queue<pair<int,int>>&q)
    {
        q.push({start,-1});
        vis[start]=true;
        
        while(!q.empty())
        {
            int curr_node=q.front().first;
            int prev_node=q.front().second;
            
            q.pop();
            
            for(auto itr:adj[curr_node])
            {
                if(!vis[itr])
                {
                    vis[itr]=true;
                    q.push({itr,curr_node});
                }
                else if(prev_node!=itr)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //concept->any node other than parent node is visited then cycle is present 
        //happy coding
        
        vector<bool>vis(V+1,false);
        queue<pair<int,int>>q;//(curr_node,prev_node)
        
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(iscycle(i,adj,vis,q))
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends