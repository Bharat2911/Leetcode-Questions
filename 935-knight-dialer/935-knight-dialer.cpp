class Solution {
public:
    long long  mod=1000000007;
//          n    i  j
    int dp[5001][5][4];
    int solve(int k,int i,int j)
    {
        //couple of base cases
        
        if(i<0 || i>=4  || j<0 || j>=3 )//out of boundary cases
        {
            return 0;
        }
        
        //case for when we encounter '*' and '#'
            //case of '*'      case of '#'
        if((i==3 and j==0) || (i==3 and j==2))
        {
            return 0;
        }
        
        if(k==1)//we have to make the n length digits
        {
            //n cant be 0 beacuse no sense of 0 length digits
            
            return 1;
        }
        
        if(dp[k][i][j]!=-1)return dp[k][i][j];
        
        //simply itrate in all the eight direction kinght moves
        
        
      int a=solve(k-1,i+1,j-2)%mod;
            a=(a+solve(k-1,i+1,j+2))%mod;
            a=(a+solve(k-1,i+2,j-1))%mod;
            a=(a+solve(k-1,i+2,j+1))%mod;
            a=(a+solve(k-1,i-1,j-2))%mod;
            a=(a+solve(k-1,i-1,j+2))%mod;
            a=(a+solve(k-1,i-2,j-1))%mod;
            a=(a+solve(k-1,i-2,j+1))%mod;
            
        return dp[k][i][j]=a;
    }
    int knightDialer(int n) {
        
        //simply do the dfs here
        
        int row=4;
        int col=3;
        
        int ans=0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans=(ans+solve(n,i,j))%mod;
            }
        }
        return ans;
    }
};