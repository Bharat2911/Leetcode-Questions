class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char,int>map;
        
        for(auto itr:s)
        {
            map[itr]++;
        }
        
        int i=0;
        
        char ans;
        
        int n=t.length();
        
        for(int i=0;i<n;i++)
        {
            if(map.find(t[i])==map.end()) // means not present in map
            {
                ans=t[i];
            }
            else
            {
                //if present in map
                map[t[i]]--;
                
                if(map[t[i]]==0)
                {
                    map.erase(t[i]);
                }
            }
        }
        return ans;
    }
};