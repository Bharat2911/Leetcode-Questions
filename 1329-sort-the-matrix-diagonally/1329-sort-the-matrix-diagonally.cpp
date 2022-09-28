class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int row=mat.size();
        int col=mat[0].size();
        
        vector<vector<int>>ans(row,vector<int>(col));
        
        //map ->int min head
        // priority_queue<int,vector<int>,greater<int>>pq;
        
        unordered_map<int,  priority_queue<int,vector<int>,greater<int>>>map;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                map[i-j].push(mat[i][j]);
            }
        }
        
       for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    ans[i][j]=map[i-j].top();
                    map[i-j].pop();
                }

            }
        return ans;
        
    }
};