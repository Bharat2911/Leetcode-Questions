//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int dt) 
                 {
                    
                    //apan isko floyd warshal se karenge
                    //cost matrix bana lo dost
                    vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
                    
                    for(int i=0;i<edges.size();i++)
                    {
                        int u=edges[i][0];
                        int v=edges[i][1];
                        int w=edges[i][2];
                        
                        cost[u][v]=w;
                        cost[v][u]=w;
                    
                        
                    }
                    
                    for(int i=0;i<n;i++)cost[i][i]=0;//we knw that from itself to iteself its 0
                    
                    //ab ispe  floyd varshsal laga do dost
                    for(int via=0;via<n;via++)
                    {
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                if(cost[i][via]==INT_MAX || cost[via][j]==INT_MAX)
                                {
                                    continue;
                                }
                                cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                            }
                        }
                    }
                    int city=-1;
                   
                    int max_count=n+1;
                    
                    for(int i=0;i<n;i++)
                    {
                         int count=0;
                         
                        for(int j=0;j<n;j++)
                        {
                            if(cost[i][j]<=dt)
                            {
                                count++;
                            }
                        }
                        if(count<=max_count)
                        {
                            max_count=count;
                            city=i;
                        }
                    }
                    return city;
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends