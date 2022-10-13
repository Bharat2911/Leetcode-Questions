//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // this question is similar to diakstra's algorithm
    int countPaths(int n, vector<vector<int>>& roads) {
        int x = pow(10,9)+1, mod = pow(10,9)+7;;
        vector<pair<int,int>> adj[n];
        vector<int> Time(n,x);
        int ans=0;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],wt=roads[i][2];
            adj[u].push_back(make_pair(wt,v));
            adj[v].push_back(make_pair(wt,u));
        }
        
        // creating a min heap priority_queue
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        // making the source which is 0 time as 0
        Time[0]=0;
        pq.push(make_pair(0,0));
        
        while(!pq.empty()){
            
            auto it = pq.top();
            
            int u=it.second;
            pq.pop();
            
            for(auto it1:adj[u]){
                int v = it1.second;
                int tim = it1.first;
                if(v==n-1){
                    if(Time[v]==Time[u]+tim){
                        ans=(ans+1)%mod;
                    }
                    else if(Time[u]+tim<Time[v]){
                        ans=1;
                        Time[v]=Time[u]+tim;
                    }
                }
                else{
                    if(Time[u]+tim<=Time[v]){
                        Time[v]=Time[u]+tim;
                        pq.push(make_pair(Time[v],v));
                    }
                }
                
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends