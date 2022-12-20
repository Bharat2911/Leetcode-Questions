class Solution {
public:
    void solve(int start,vector<int>adj[],vector<int>&vis)
    {
        queue<int>q;
        
        q.push(start);
        vis[start]=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto itr:adj[node])
            {
                if(!vis[itr])
                {
                    vis[itr]=1;
                    q.push(itr);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        //we will treat it as an graph problem
        
        //step one make the adj list
        
        int n=rooms.size();
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        vector<int>vis(n,0);
        
        bool flag=false;
        
        int start=0;
        
        solve(start,adj,vis);
        
        for(auto itr:vis)
        {
            if(itr==0)
            {
                flag=true;
            }
        }
        if(flag)return false;
        
        else return true;
    }
};