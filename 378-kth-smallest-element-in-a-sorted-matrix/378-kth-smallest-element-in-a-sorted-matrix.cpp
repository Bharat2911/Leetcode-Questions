class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //brute force 
        //T.c=O(n^2)
        //s.c=O(n+n);
        
        
        vector<int>ans;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};