class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            
            solve(idx+1,nums,ans);
            
            //backtracking step
            swap(nums[idx],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
     
        int n=nums.size();
        
        vector<vector<int>>ans;
        
        // vector<int>res;
        
        int idx=0;
        
        solve(idx,nums,ans);
        
        return ans;
    }
};