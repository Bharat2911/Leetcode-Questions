class Solution {
public:
    bool check(vector<int>&arr)
    {
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                return false;
            }
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        unordered_map<int,vector<int>>map;
        
        int row=matrix.size();
        
        int col=matrix[0].size();
        
        int diag=col+row-1;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                map[i-j].push_back(matrix[i][j]);
            }
        }
       
        vector<vector<int>>ans;
        
        for(auto itr:map)
        {
            ans.push_back(itr.second);
        }
        
        for(int i=0;i<ans.size();i++)
        {
            if(!check(ans[i]))
            {
                return false;
            }
        }
        return true;
    }
};