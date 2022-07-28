class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //make the freq arr both the strings if its same then return true else false
        int n=s.length();
        int m=t.length();
        
        vector<int>for_s(26,0);
        vector<int>for_p(26,0);
        
        for(int i=0;i<n;i++)
        {
            for_s[s[i]-'a']++;
        }
        
        for(int j=0;j<m;j++)
        {
            for_p[t[j]-'a']++;
        }
        
        if(for_s==for_p)
        {
            return true;
        }
        
        return false;
        
    }
};