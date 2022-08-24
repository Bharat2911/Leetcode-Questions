class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        
        int i=0;
        int j=0;
        
        unordered_map<char,int>map;
        
        int ans=0;
        
        while(j<n)
        {
            map[s[j]]++;
            
            //do case
            
            while(map.size()<j-i+1)
            {
                //shrink 
                
                map[s[i]]--;
                
                if(map[s[i]]==0)
                {
                    map.erase(s[i]);
                }
                i++;
            }
            
            if(map.size()==j-i+1)
            {
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};