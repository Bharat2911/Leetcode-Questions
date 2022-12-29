class Solution {
public:
    int numSub(string s) {
        
        //its ans easy one man
        int mod=1e9+7;
        
        int ans=0;
        
        long long count=0;
        
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]=='1')
            {
                count++;
            }
            else 
            {
               if(count>0)
               {
                   ans+=((count+1)*count/2)%mod;
                   
               }
                count=0;
            }
        }
        ans+=(count+1)*count/2;
        
        return ans%mod;
    }
};