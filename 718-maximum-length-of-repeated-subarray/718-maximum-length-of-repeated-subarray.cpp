class Solution {
public:
    int findLength(vector<int>& num1, vector<int>& num2) {
        
        int n=num1.size();
        int m=num2.size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        int ans=0;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(num1[i-1]==num2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
               
            }
        }
        return ans;
    }
};