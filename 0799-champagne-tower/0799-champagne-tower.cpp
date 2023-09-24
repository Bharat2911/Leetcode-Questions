class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
          //dp matrix;
        double dp[101][101]={0.0};
        
        dp[0][0]=poured;//first glass me poured 
        
        //itrate in the all rows and an the glass
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(dp[i][j]>=1)
                { 
                    //spilit acc to levels
                    dp[i+1][j]+=(dp[i][j]-1)/2.0;
                    dp[i+1][j+1]+=(dp[i][j]-1)/2.0;
                    dp[i][j]=1;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};