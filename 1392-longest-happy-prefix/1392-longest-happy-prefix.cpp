class Solution {
public:
    string longestPrefix(string s) {
        
        //we have to find a longest prfix that is also a suffix
        
        int n=s.length();
        
        vector<int>lps(n,0);
        
        int i=1;
        int j=0;
        
        string ans;
        
        while(i<n)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
            }
        }
        int len=lps.back();
        
        for(int i=0;i<len;i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};