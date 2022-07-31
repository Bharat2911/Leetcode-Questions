class Solution {
public:
    //implimenting the djstras algorithmn
    
    vector<int>solve(vector<pair<int,int>>adj[],int src,int n)
    {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	vector<int>distance(n,INT_MAX);
	distance[src]=0;
	q.push({0,src});

	while(!q.empty()){
		int dist= q.top().first;
		int prev = q.top().second;
		q.pop();
		for(auto x: adj[prev]){
			int next = x.first;
			int nextDistance = x.second;
			if(distance[next]>dist+nextDistance){
				distance[next] = dist+nextDistance;
				q.push({distance[next],next});
			}
		}
	}
	return distance; 
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        

        //making the adj list
        //int adj we will store the node with its edge weight (`1)
        int n=edges.size();
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            {
                adj[i].push_back({edges[i],1});//we are taking weight as one here
                
            }
        }
        
        vector<int>dist1=solve(adj,node1,n);
        vector<int>dist2=solve(adj,node2,n);
        
        int ans=0;
        int maxi=INT_MAX;
        int res=-1;
        
        
        for(int i=0;i<n;i++)
        { 
           if(dist1[i]!=INT_MAX and dist2[i]!=INT_MAX)
           {
               if(maxi>max(dist1[i],dist2[i]))
               {
                   maxi=max(dist1[i],dist2[i]);
                   res=i;
               }
           }
        }
        return res;
    }
};