class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //using the freuency array bitch
        int n=s.length();
        
        int m=t.length();
        
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        
        for(auto itr:s)
        {
            h1[itr-'a']++;
        }
        
        for(auto itr:t)
        {
            h2[itr-'a']++;
        }
        
        if(h1==h2)
        {
            return true;
        }
        return false;
        
    }
};