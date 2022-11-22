class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>dp(n+1,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};