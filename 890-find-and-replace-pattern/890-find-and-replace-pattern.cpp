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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        //lets try this by appplying the concept of isomorphic strings
        vector<string>ans;
        
        for(int i=0;i<words.size();i++)
        {
            if(solve(pattern,words[i]))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};