class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int row=mat.size();
        int col=mat[0].size();
        
        vector<pair<int,int>>ans;
        
        for(int i=0;i<row;i++)
        {
            int count=0;
            
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            
            ans.push_back({count,i});
        }
        
        sort(ans.begin(),ans.end());
        
        vector<int>res;
        
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].second);
        }
        return res;
    }
};