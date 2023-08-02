class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans,vector<int>&res)
    {
        if(idx==nums.size())
        {
            ans.push_back(res);
            
            return;
        }
        //pick
        
        res.push_back(nums[idx]);
        solve(idx+1,nums,ans,res);
        
        //not pick
        
        res.pop_back();
        solve(idx+1,nums,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        vector<int>res;
        
        int idx=0;
        
        solve(idx,nums,ans,res);
        
        return ans;
    }
};