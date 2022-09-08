class Solution {
public:
    //leadinh spce vala case galat ho rha jai
    int myAtoi(string s) {
        
        int n=s.length();
        
        long long int num=0;
        
        int i=0;
        
        if(s[i]=='+' and s[i+1]=='-')return 0;
        if(s[i]=='-' and s[i+1]=='+')return 0;
        
        int sign=1;
        
        //leading space case
        //jab tak space mile usko ignore karo
        while(s[i]==' ')
        {
            i++;
        }
        
        if(s[i]=='+')
        {
            sign=1;
            i++;
        }
        
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        
        while(i<n)
        {
            if(s[i]-'0'>=0 and s[i]-'0'<=9)//this is case when we get digit
            {
                num=num*10+s[i]-'0';
            }
            else
            {
                break;
            }
            
            //check for overflow
            if(num>INT_MAX)
            {
                if(sign==1)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
            
            i++;
            
        }
        return sign*(int)num;
    }
};