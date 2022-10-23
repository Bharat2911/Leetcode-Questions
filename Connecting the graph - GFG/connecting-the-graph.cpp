//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(int i,vector<int>adj[],vector<int>&vis)
    {
        vis[i]=1;
        
        for(auto itr:adj[i])
        {
            if(!vis[itr])
            {
                vis[itr]=1;
                solve(itr,adj,vis);
            }
        }
    }
    int Solve(int n, vector<vector<int>>& edge){
        // code here
        int m=edge.size();
        
        if(m<n-1)return -1;
        
        vector<int>adj[n];
        
        vector<int>vis(n,0);
        
        for(int i=0;i<edge.size();i++)
        {
            int u=edge[i][0];
            int v=edge[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                solve(i,adj,vis);
            }
        }
        return count-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<vector<int>>adj;
        
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
            
            Solution Obj;
            cout<<Obj.Solve(n,adj)<<"\n";
    }
    return 0;
}
// } Driver Code Ends