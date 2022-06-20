class Solution
{
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
        bool canVisitAllRooms(vector<vector < int>> &rooms)
        {

           	//makethe adj list and traversetha graph if graph component greater than one than false else true
            int n = rooms.size();

            vector<int> adj[n];
            
            vector<int>vis(n,0);
            
            for (int i = 0; i < rooms.size(); i++)
            {
                for (int j = 0; j < rooms[i].size(); j++)
                {
                    adj[i].push_back(rooms[i][j]);
                }
            }
            
            int count=0;//keep the count of components of the graph
            
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    count++;
                    dfs(i,adj,vis);
                }
            }
            
            if(count>1)
            {
                return false;
            }
            return true;
            
        }
};