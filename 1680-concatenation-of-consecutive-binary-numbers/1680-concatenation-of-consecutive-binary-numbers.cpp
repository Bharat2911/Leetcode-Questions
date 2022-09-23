class Solution {
public:
    string binary(int n)
    {
        string t="";
        while(n!=0)
        {
            if(n%2!=0)
            {
                t+='1';
            }
            else
            {
                t+='0';
            }
            n/=2;
        }
        reverse(t.begin(),t.end());
        return t;
    }
    int concatenatedBinary(int n) 
    {
        string s="";
        const int N=1e9+7;
        long long ans=0;
        int j=0;
        for(int i=1;i<=n;i++)
        {
            s+=binary(i); //Function  to calculate the binary of every number upto n
        }
        int m=s.length(),p=1;
        for(int i=m-1;i>=0;i--)
        {
            if(s[i]!=0)  // Checking if char is 0 or not, it prevents from TLE because we only perform operarions when s[i]=1
            {
                ans+=p*(s[i]-'0');
                ans%=N;  //Modulo 1e9+7;
            }
            p*=2;
            p%=N; //Modulo 1e9+7            
        }
        return ans;
    }
};