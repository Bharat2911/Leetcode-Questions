// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int start,vector<int>&vis,vector<vector<int>>&graph)
  {
      vis[start]=1;
      
      for(auto itr:graph[start])
      {
          if(!vis[itr])
          {
              vis[itr]=1;
              dfs(itr,vis,graph);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //we just have to count the number of components n the grph
        //using the df algorithm to find the number of compopnents
        
        //make the graph(adj list legit vali)
        
        vector<vector<int>>graph(V);
        int count=0;
        
        for(int i=0;i<V;i++)
        
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    graph[i].push_back(j);
                }
            }
        }
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,vis,graph);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends