class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        
        string output="";
        
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
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        int i=n;
        int j=m;
        
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                output.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                  if(dp[i - 1][j] > dp[i][j - 1]) {
                    output.push_back(str1[i - 1]);
                    i--;
                }
                else {
                    output.push_back(str2[j - 1]);
                    j--;
                }
            }
        }
        while(i>0)
        {
            output.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            output.push_back(str2[j-1]);
            j--;
        }
        reverse(output.begin(),output.end());
        return output;
        
    
    }
};