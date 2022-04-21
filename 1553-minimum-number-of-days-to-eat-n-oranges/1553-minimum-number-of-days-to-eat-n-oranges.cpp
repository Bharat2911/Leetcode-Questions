class Solution {
public:
    //recursion + memonization
    map<int,int>dp;
    
    int f(int n)
    {
        //base case
        if(n<=0)return 0;
        
        if(dp.find(n)!=dp.end())return dp[n];//if n map me already prent hai to directly return karo
        
        
        //choice diagram 
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        
        if(n%2==0)
        {
            a=1+f(n-n/2);
        }
         if(n%3==0)
        {
            b=1+f(n-(2*(n/3)));
        }
         if(n%2!=0 || n%3!=0)
        {
            c=1+f(n-1);
        }
        //ans
        return dp[n]=min({a,b,c});
    }
    int minDays(int n) {
        
        //using the recursion to solve this 
        
        
        return f(n);
        
    }
};