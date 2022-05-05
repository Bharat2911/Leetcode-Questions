class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        //doing the normal bfs 
        //make the adj list
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adj[manager[i]].push_back(i);
                
            }
        }
        
        queue<pair<int,int>>q;
        q.push({headID,0});
        int ans=0;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            
            int newtime=informTime[node]+time;
            
            ans=max(ans,newtime);
            
            for(auto itr:adj[node])
            {
                q.push({itr,newtime});
            }
        }
        return ans;
    }
};