//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& adj, int S) {
        // Code here
        
        //we have to do the n-1 times relaxation
        vector<int>dist(V,1e8);
        
        dist[S]=0;
        
        for(int i=0;i<V-1;i++)
        {
            for(auto itr:adj)
            {
                int u=itr[0];
                int v=itr[1];
                int w=itr[2];
                
                //this is relaxacation step man
                
                if(dist[u]!=1e8 and dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                }
            }
        }
        //do one more ralaxation and if dist changes return 1
        //means if we have the negative cycle return 1
        for(auto itr:adj)
        {
            int u=itr[0];
            int v=itr[1];
            int w=itr[2];
            
            if(dist[u]!=1e8 and dist[u]+w<dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends