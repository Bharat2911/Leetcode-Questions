class Solution {
public:
    bool isHappy(int n) {
        
        int sum=0;
        
        while(n>0)
        {
            int m=n%10;
            sum+=m*m;
            n=n/10;
            
            if(sum==89)return false;
            if(n==0)
            {
                if(sum==1)return true;
                n=sum;
                sum=0;
            }
        }
        return false;
    }
};