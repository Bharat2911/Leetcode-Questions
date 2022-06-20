class Solution {
public:
    void solve(int index,vector<int>&nums,vector<vector<int>>&res,vector<int>&ans)
    {
        res.push_back(ans);
        
        for(int i=index;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
            
            solve(i+1,nums,res,ans);
            
            
            ans.pop_back();
            
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>>res;
        vector<int>ans;
        
        solve(0,nums,res,ans);
        
        return res;
    }
};