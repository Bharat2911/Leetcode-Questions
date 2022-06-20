class Solution {
public:
    void solve(int index,vector<int>&nums,vector<vector<int>>&res,vector<int>&ans)
    {
        //base case
        if(index==nums.size())
        {
            res.push_back(ans);
            return;
        }
        
        //pick
        ans.push_back(nums[index]);
        solve(index+1,nums,res,ans);
        
        //not pick 
        //backtrak it
        ans.pop_back();
        solve(index+1,nums,res,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>>res;
        vector<int>ans;
        
        solve(0,nums,res,ans);
        
        return res;
    }
};