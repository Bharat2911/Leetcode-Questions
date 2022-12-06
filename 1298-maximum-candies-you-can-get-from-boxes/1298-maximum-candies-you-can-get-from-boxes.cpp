class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
         int n=status.size();
        vector<int>isopen(n,0);
        for(int i=0;i<n;i++)
        {
            if(status[i]==1)
            {
                isopen[i]=1;
            }
        }
        int total=0;
        vector<int>visited(n,0);
        vector<int>opened(n,0);
        queue<int>q;
        for(auto it:initialBoxes)
        {
            q.push(it);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(visited[x]==1)
                continue;
            visited[x]=1;
            if(isopen[x]==1)
            {
                total+=candies[x];
                opened[x]=1;
            }
            for(auto it:keys[x])
            {
                isopen[it]=1;
                if(visited[it]==1 and opened[it]==0)
                {
                    opened[it]=1;
                    total+=candies[it];
                }
            }
            for(auto it:containedBoxes[x])
            {
                q.push(it);
            }

        }
        return total;
    }
};