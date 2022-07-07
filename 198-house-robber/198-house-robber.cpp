class Solution {
public:
    
    int solve(int index,vector<int>&nums,int n,vector<int>&dp)
    {
        //bae case
        if(index>n-1)
        {
            return 0;
        }
        
        if(dp[index]!=-1)return dp[index];
        
        //two options 
        
        int pick = nums[index]+solve(index+2,nums,n,dp);//i cant choose the ele next to it
        
        int not_pick=solve(index+1,nums,n,dp);
        
        
        return dp[index]=max(pick,not_pick);
        
    }
    int rob(vector<int>& nums) {
        
        //we will be writing a recursion function
        
        //concept -. if we choose the curr ele then we cant take the ele just next to i t
        
        int index=0;
        
        int n=nums.size();
        
        vector<int>dp(n,-1);
        
        
        return solve(index,nums,n,dp);
        
    }
};