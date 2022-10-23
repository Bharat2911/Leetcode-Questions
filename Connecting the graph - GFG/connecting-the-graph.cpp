//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class disjoint{
    
    public:
    vector<int>parent;
    vector<int>size;
    
    disjoint(int v)
    {
        parent.resize(v+1);
        size.resize(v+1,1);
        
        for(int i=0;i<=v;i++)
        {
            parent[i]=i;
            
        }
    }
    int findparent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        
        return parent[node]=findparent(parent[node]);
    }
    
    void unionbysize(int u,int v)
    {
        int pu=findparent(u);
        
        int pv=findparent(v);
        
        if(pu==pv)return;
        
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& connections){
        // code here
        disjoint dv(n);
        
        //make the adj list
        vector<int>adj[n];
        
        int extra_edges=0;
        
       for(auto itr:connections)
       {
           int u=itr[0];
           int v=itr[1];
           
           if(dv.findparent(u)==dv.findparent(v))
           {
               extra_edges++;
           }
           dv.unionbysize(u,v);
       }
        int comp=0;
        
        for(int i=0;i<n;i++)
        {
            if(dv.parent[i]==i)comp++;
        }
        int ans=comp-1;
        
        if(extra_edges>=ans)return ans;
        return -1;
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