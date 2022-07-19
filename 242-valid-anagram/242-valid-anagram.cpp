class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //two freq array if both are same then return true else return fasle
        
        vector<int>for_s(26,0);
        vector<int>for_p(26,0);
        
        if(s.length()!=t.length())return false;
        
        
        for(int i=0;i<s.length();i++)
        {
            for_s[s[i]-'a']++;
            for_p[t[i]-'a']++;
        }
        
        
        if(for_s!=for_p)return false;
        return true;
    }
};