class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans,vector<int>&res)
    {
        
        ans.push_back(res);
        
        for(int i=idx;i<nums.size();i++)
        {
            if(i>0 and i!=idx and nums[i]==nums[i-1])continue;
            
            res.push_back(nums[i]);
            
            solve(i+1,nums,ans,res);
            
            res.pop_back();//backtraking step'
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        vector<int>res;
        
        int idx=0;
        
        solve(idx,nums,ans,res);
        
        return ans;
    }
};