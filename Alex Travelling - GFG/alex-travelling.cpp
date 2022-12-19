//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto itr:flights)
        {
            int u=itr[0];//convert kiya 0 based index me
            int v=itr[1];
            int w=itr[2];
            
            //direct graph
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //pq->{dist,node}
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty())
        {
            int prev_dist=pq.top().first;
            int prev_node=pq.top().second;
            pq.pop();
            
            for(auto itr:adj[prev_node])
            {
                int v=itr.first;
                int w=itr.second;
                
                if(dist[v]>dist[prev_node]+w)
                {
                    dist[v]=dist[prev_node]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(ans,dist[i]);
        }
        if(ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends