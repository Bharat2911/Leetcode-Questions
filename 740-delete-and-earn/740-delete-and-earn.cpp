class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
         vector<int>dp(10001,0);
        vector<int>sum(10001,0);
        
        for(auto i:nums)
        {
            sum[i]+=i;
        }
        dp[0]=0;
        dp[1]=sum[1];
        
        //similar to house robber 
        
        for(int i=2;i<10001;i++)
        {
            //if take the current elemnt cant take the adjacent elemnt
            //else simply take the adjacent and max of both will be our aswer
            dp[i]=max(sum[i]+dp[i-2],dp[i-1]);
        }
        return dp[10001-1];
    }
};