class Solution {
public:
   
    bool solve(int idx,vector<int>&nums,int sum,vector<vector<int>>&dp)
    {
        //base case
        if(idx==nums.size())
        {
            return false;
        }
        
        if(sum==0)
        {
            return true;
        }
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        if(nums[idx]<=sum)
        {
            //pick or not pick
            return dp[idx][sum]=solve(idx+1,nums,sum-nums[idx],dp) || solve(idx+1,nums,sum,dp);
        }
        else
        {
            //not pick
            return dp[idx][sum]=solve(idx+1,nums,sum,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        
        
        int total_sum=0;
        
        for(auto itr:nums)
        {
            total_sum+=itr;
        }
        vector<vector<int>>dp(n+1,vector<int>(total_sum+1,-1));
        if(total_sum%2!=0)
        {
            return false;
        }
        
        int sum=total_sum/2;
        int idx=0;
        return solve(0,nums,sum,dp);
    }
};