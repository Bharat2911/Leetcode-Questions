class Solution {
public:
    double myPow(double x, int n) {
        
        double ans=1.00;
        long long m = n;
        if(m<0)
            m=-1*m;
        
        while(m)
        {
            if(m%2==0)
            {
                x=x*x;
                m=m/2;
            }
            else
            {
                ans*=x;
                m=m-1;
            }
        }
        return n<0?1/ans:ans;
    }
};