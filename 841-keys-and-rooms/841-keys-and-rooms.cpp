class Solution {
public:
    void dfs(int start,vector<int>adj[],vector<int>&vis)
    {
        vis[start]=1;
        
        for(auto itr:adj[start])
        {
            if(!vis[itr])
            {
                dfs(itr,adj,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        //conclusion is that 
        //if components greater than 0 than false
        //else true
         
        
        //step one make the adj list
        int n=rooms.size();
        
        vector<int>adj[n];
        vector<int>vis(n,0);
        
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                count++;
            }
        }
        
        if(count>1)return false;
        return true;
    }
};