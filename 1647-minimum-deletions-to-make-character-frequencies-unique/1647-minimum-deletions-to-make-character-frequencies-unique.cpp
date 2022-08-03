class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        
        vector<int>freq(26,0);
        
        unordered_map<int,int>map;
        
        for(auto itr:s)
        {
            freq[itr-'a']++;
        }
        
        int count=0;
        
        for(auto itr:freq)
        {
            while(itr!=0 and map.find(itr)!=map.end())
            {
                count++;
                itr--;
            }
            if(itr>0)
            {
                map[itr]++;
            }
        }
        return count;
    }
};