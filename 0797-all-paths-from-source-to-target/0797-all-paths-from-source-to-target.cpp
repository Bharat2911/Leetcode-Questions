class Solution
{
    public:
    //approach->dfs/bfs+backtracking man
        void dfs(int start, vector<vector < int>> &graph, vector< vector< int >> &ans, vector< int > path, int target)
        {
            path.push_back(start);

           	//base case meri jaan
            if (start == target)
            {
                ans.push_back(path);
                return;
            }
            else
            {
               	//itrate into adjacent 
                for (auto itr: graph[start])
                {
                    dfs(itr, graph, ans, path, target);
                }
            }
            path.pop_back();	//backtracking step meri jaan
        }
    vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
    {

        int n = graph.size();

        vector<vector < int>> ans;

        vector<int> path;

        int target = n - 1;

        dfs(0, graph, ans, path, target);

        return ans;
    }
};