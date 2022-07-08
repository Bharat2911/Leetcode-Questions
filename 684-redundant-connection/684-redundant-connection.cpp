class Solution {
    
    bool DFS(int v, int p, vector<list<int>> &adjList, vector<bool> &visited, vector<int> &path)
    {
        visited[v] = true;
        path.push_back(v);
        for(auto node : adjList[v])
        {
            if(!visited[node])
            {
                if(DFS(node, v, adjList, visited, path))
                    return true;
            } 
            else if(node != p)
            {
                path.push_back(node);
                return true;
            }
                
        }
        path.pop_back();
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<list<int>> adjList(edges.size() + 1);
        
        for(auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
            
        
        vector<int> path;
        vector<bool> visited(edges.size() + 1, false);
        
        DFS(1, -1, adjList, visited, path);
        
        unordered_set<int> s1;
        int index = std::find(path.begin(), path.end(), path.back()) - path.begin();
        for(int i = index; i < path.size() - 1; i++)
        {
            s1.insert(path[i]); 
            s1.insert(path[i+1]); 
        }
              
        
        for(int i = edges.size() - 1; i >= 0; i--)
        {
            if(s1.find(edges[i][0]) != s1.end() && s1.find(edges[i][1]) != s1.end())
                return vector<int>{edges[i][0], edges[i][1]};
        }
        
        return vector<int>{};
        
    }
};
