class Solution {
public:
    bool solve(int idx,vector<int>&nums,int sum,int n,vector<vector<int>>&dp)
    {
        if(idx==n)
        {
            return false;
        }
        
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        
        if(sum==0)
        {
            return true;
        }
        
        if(nums[idx]<=sum)
        {
            return dp[idx][sum]=solve(idx+1,nums,sum-nums[idx],n,dp) || solve(idx+1,nums,sum,n,dp);
        }
        else
        {
            return dp[idx][sum]=solve(idx+1,nums,sum,n,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        
        //recurion
        int n=nums.size();
        
        int sum=0;
        
        for(auto itr:nums)
        {
            sum+=itr;
        }
        
        int idx=0;
        
        if(sum%2!=0)
        {
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return solve(idx,nums,sum/2,n,dp);
    }
};