class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        if(n!=m)
        {
            return false;
        }
        
        int m1[256]={0};
        int m2[256]={0};
        
        for(int i=0;i<n;i++)
        {
            if(!m1[s[i]] and !m2[t[i]])
            {
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m1[s[i]]!=t[i])
            {
                return false;
                
            }
        }
        return true;
    }
};