class Solution {
public:
    int minDeletions(string s) {
        
        int count=0;
        
        int n=s.length();
        
        vector<int>freq(26,0);
        
        for(auto itr:s)
        {
            freq[itr-'a']++;
        }
        
        unordered_map<int,int>map;
        
        for(auto itr:freq)
        {
            while(itr!=0 and map.find(itr)!=map.end())
            {
                itr--;
                count++;
            }
            if(itr>0)
            {
                map[itr]++;
            }
        }
        return count;
    }
};