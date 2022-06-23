class Solution {
public:
    bool iscycle(vector<int>adj[],int n)
    {
//         vector<int>indegree(n,0);
        
//         queue<int>q;
//         int count=0;
        
//         for(int i=0;i<n;i++)
//         {
//             for(auto itr:adj[i])
//             {
//                 indegree[itr]++;
//             }
//         }
//         //in queue jiski indegree zero nahi hogi vo node push hoga
//         for(int i=0;i<n;i++)
//         {
//             if(indegree[i]!=0)
//             {
//                 q.push(i);
//             }
//         }
//         while(!q.empty())
//         {
//            int temp=q.front();
//             q.pop();
            
//             count++;
            
//             for(auto itr:adj[temp])
//             {
//                 indegree[itr]--;
                
//                 if(indegree[itr]==0)
//                 {
//                     q.push(itr);
//                 }
//             }
//         }
//         if(count==n)return false;
//         return true;
        vector<int>indegree(n,0);
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
            
        }
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            count++;
            for(auto x:adj[i])
            {
                indegree[x]--;
                
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(count==n)return false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        //just check the cycle in the firected graph
        int m=edges.size();
        
        vector<int>adj[n];
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            
            
        }
        if(iscycle(adj,n))return false;
        
        return true;
    }
};