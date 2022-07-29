class Solution {
public:
    bool solve(string &s,string &t)
    {
         int n=s.length();
        int m=t.length();
        
        if(n!=m)
        {
            return false;
        }
        
       map<char,char>map;
        
        for(int i=0;i<n;i++)
        {
            if(map.find(s[i])!=map.end())
            {
                if(map[s[i]]!=t[i])
                {
                    return false;
                }
            }
            else
            {
                map[s[i]]=t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        
       return solve(s,t) and solve(t,s);
        
    }
};