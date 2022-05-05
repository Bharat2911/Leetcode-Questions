// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int>&vis,vector<int>adj[])
	{
	    vis[i]=1;
	    
	    for(auto itr:adj[i])
	    {
	        if(!vis[itr])
	        {
	            
	            
	            dfs(itr,vis,adj);
	        }
	    }
	    
	    
	}
	void topo(int i,vector<int>&vis,vector<int>adj[],stack<int>&st)
	{
	    vis[i]=1;
	    
	    for(auto itr:adj[i])
	    {
	        if(!vis[itr])
	        {
	            
	            
	            topo(itr,vis,adj,st);
	        }
	    }
	    st.push(i);
	    
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        //simply implitation of kosarajus
        vector<int>vis(V,0);
        stack<int>st;
        //implimenting the toppo sort
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                topo(i,vis,adj,st);
            }
        }
        
        //reversing the adjlist
        //and reset the visited vector to zero again
         vector<int>transpose[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;//reseting th evisited vector to 0
            for(auto x:adj[i])
            {
                transpose[x].push_back(i);//first i connected to x i connecter x to i
            }
        }
        
        int count=0;
        //now i have to itrate in the order we have in stack
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            
           if(!vis[top])
           {
               count++;
               dfs(top,vis,transpose);
           }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends