class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        //approach bna gyi ab implimentation karna main hai bro jiiii
        int row=mat.size();
        int col=mat[0].size();
        
        // vector<int>ans;
        vector<vector<int>>ans(row+col);
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            if(i%2==0)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        
        vector<int>res;
        
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                res.push_back(ans[i][j]);
            }
        }
        return res;
    }
};