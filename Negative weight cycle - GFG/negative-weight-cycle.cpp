// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>adj){
	    // Code here
	    //simply in this we have to do the n-1 time relaxation
	    int dist[n];
	    memset(dist,INT_MAX,sizeof dist);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++)
	    {
	        for (auto itr:adj)
	        {
	            int u=itr[0];
	            int v=itr[1];
	            int w=itr[2];
	            
	            if(dist[u]+w<dist[v])
	            {
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    //now do one more time relaxation
	    bool iscycle=false;
	     for(int i=0;i<n-1;i++)
	    {
	        for (auto itr:adj)
	        {
	            int u=itr[0];
	            int v=itr[1];
	            int w=itr[2];
	            
	            if(dist[u]+w<dist[v])
	            {
	                iscycle=true;
	            }
	        }
	    }
	    return iscycle;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends