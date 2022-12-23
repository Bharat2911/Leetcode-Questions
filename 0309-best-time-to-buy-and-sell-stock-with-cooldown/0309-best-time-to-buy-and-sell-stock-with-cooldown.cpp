class Solution {
public:
    int solve(int idx,vector<int>&nums,bool is_buy,vector<vector<int>>&dp)
    {
        //base
        
        if(idx>=nums.size())
        {
            return 0;
        }
        if(dp[idx][is_buy]!=-1)return dp[idx][is_buy];
        
        int profit=0;
        
        if(is_buy)
        {
           profit=max(-nums[idx]+solve(idx+1,nums,false,dp),solve(idx+1,nums,true,dp));    
        }
        else
        {
            //not allowed to buy i can only sell
            profit=max(nums[idx]+solve(idx+2,nums,true,dp),solve(idx+1,nums,false,dp));
        }
        return dp[idx][is_buy]=profit;
    }
    int maxProfit(vector<int>& nums) {
        
         int n=nums.size();
        
        int idx=0;
        
        bool is_buy=true;
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        return solve(idx,nums,is_buy,dp);
    }
};