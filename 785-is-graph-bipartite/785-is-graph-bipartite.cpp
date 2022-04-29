class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        //we will make a color vector that will also be treated as visted vector

          int n=graph.size();
        
        vector<int>color(n,-1);
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
            color[i]=0;
            }
          
            
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                
                for(auto x:graph[temp])
                {
                    if(color[x]==-1)
                    {
                        q.push(x);
                        color[x]=1-color[temp];
                    }
                    else if(color[x]==color[temp])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};