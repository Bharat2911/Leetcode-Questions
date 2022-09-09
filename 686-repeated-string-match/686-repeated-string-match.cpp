class Solution
{
    public:
  bool  issubstr(string a,string b)
    {
        
        int n=a.length();
        int m=b.length();
        
        for(int i=0;i<=m-n;i++)
        {   
            int j=0;
            
            for( j=0;j<n;j++)
            
                if(b[i+j]!=a[j])break;
                
              if(j==n)return true;  
            
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        
        //we will have the impliment the substring function
        int n=a.length();
        int m=b.length();
        
        string s=a;
        int ans=1;
        
        while(s.length()<m)
        {
            s+=a;
            ans++;
        }
        
        
        if(issubstr(b,s))  return ans;
        
        if(issubstr(b,s+a))return ans+1;
        
        return -1;
        
        }
};