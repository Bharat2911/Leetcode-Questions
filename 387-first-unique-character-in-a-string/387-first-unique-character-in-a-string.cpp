class Solution {
public:
    int firstUniqChar(string s) {
        
       unordered_map<char,int>map;
        for(auto itr: s)
            {
            map[itr]++;
        }
        for(int i=0;i<s.length();i++)
            {
            if(map[s[i]]==1)
                {
                return i;
                break;
            }
        }
        return -1;
    }
};