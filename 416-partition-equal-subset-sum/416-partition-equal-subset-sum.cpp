class Solution {
    bool solve(vector<int>&nums,int sum,int n)
    {
        int dp[n+1][sum+1];
        
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }
        for(int j=1;j<sum+1;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
        
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(sum&1)return false;
        
        return solve(nums,sum/2,n);
        
    }
};