class Solution {
public:
    int solve(int idx,vector<int>&nums,bool is_buy,vector<vector<vector<int>>>&dp,int k)
    {
        //base
        
        if(idx==nums.size() || k==0)
        {
            return 0;
        }
        
        if(dp[idx][is_buy][k]!=-1)return dp[idx][is_buy][k];
        
        int profit=0;
        
        if(is_buy)
        {
           profit=max(-nums[idx]+solve(idx+1,nums,false,dp,k),solve(idx+1,nums,true,dp,k));    
        }
        else
        {
            //not allowed to buy i can only sell
            profit=max(nums[idx]+solve(idx+1,nums,true,dp,k-1),solve(idx+1,nums,false,dp,k));
        }
        return dp[idx][is_buy][k]=profit;
    }
    int maxProfit(vector<int>& nums) {
        
      int n=nums.size();
        
        int idx=0;
        
        bool is_buy=true;
        
        int k=2;
        
        //isme apan 3-d dp banayege kyuki teen cheeze change ho rhi hai
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return solve(idx,nums,is_buy,dp,k);
    }
};