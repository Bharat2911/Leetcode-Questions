class Solution {
public:
    int dp[101];
    
    int solve(int idx,vector<int>&nums,int n)
    {
        //base case
        
        if(idx>=n)
        {
            return 0;
        }
        
        if(dp[idx]!=-1)return dp[idx];
        
        //now we have two case
        //case 1->robbed the current house then cant rob the next adjacent house
        //case 2->dont robbed the current house robbed the next house
        
        int a=nums[idx]+solve(idx+2,nums,n);
        
        int b=solve(idx+1,nums,n);
        
        return dp[idx]=max(a,b);
        
    }
    int rob(vector<int>& nums) {
        
        //if robbed current house then cant robberd the house next to it
        
        int n=nums.size();
        int idx=0;
        memset(dp,-1,sizeof dp);
        
        return solve(idx,nums,n);
    }
};