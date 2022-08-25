class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int>map1(26,0);
        vector<int>map2(26,0);
        
        for(int i=0;i<ransomNote.length();i++)
        {
            map1[ransomNote[i]-'a']++;
        }
        
        for(int i=0;i<magazine.length();i++)
        {
            map2[magazine[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(!(map1[i]<=map2[i]))
            {
                return false;
            }
        }
        return true;
    }
};