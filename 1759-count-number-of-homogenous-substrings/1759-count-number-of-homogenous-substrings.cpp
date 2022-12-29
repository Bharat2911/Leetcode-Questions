class Solution {
public:
    int countHomogenous(string s) {
     
        int n=s.length();
        
        long long count=1;
        
        int ans=0;
        
        int mod=1e9+7;
        
        char ch=s[0];
        
        for(int i=1;i<n;i++)
        {
            
            if(s[i]==ch)
            {
                count++;
            }
            else
            {
                ch=s[i];
                
                ans+=((count+1)*count/2)%mod;
                
                count=1;//reset the counter
            }
            
            
        }
        ans+=((count+1)*count/2)%mod;
        
        return ans%mod;
    }
};