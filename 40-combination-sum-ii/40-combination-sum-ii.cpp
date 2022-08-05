class Solution {
public:
    void solve(int idx,vector<int>&nums,int sum,vector<vector<int>>&res,vector<int>&ans)
    {
        if(sum==0)
        {
            res.push_back(ans);
            return;
        }
        if(sum<0)
        {
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i]==nums[i-1])continue;
            ans.push_back(nums[i]);
            
            solve(i+1,nums,sum-nums[i],res,ans);
            
            ans.pop_back();//backtraking step;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int idx=0;
        
        vector<vector<int>>res;
        vector<int>ans;
        
        solve(idx,nums,sum,res,ans);
        
        return res;
    }
};