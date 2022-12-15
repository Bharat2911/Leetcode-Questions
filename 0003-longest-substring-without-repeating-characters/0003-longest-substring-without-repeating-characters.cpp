class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        int n=s.length();
        
        unordered_map<char,int>map;
        
        int i=0;
        int j=0;
        
        int ans=0;
        
        
        while(j<n)
        {
            map[s[j]]++;
            
            
            if(map.size()<j-i+1)
            {
                while(map.size()<j-i+1)
                {
                    //shrink the window
                    map[s[i]]--;
                    
                    if(map[s[i]]==0)
                    {
                        map.erase(s[i]);
                    }
                    i++;
                }
            }
            else if(map.size()==j-i+1)
            {
                ans=max(ans,j-i+1);
                
            }
            j++;
        }
        return ans;
    }
};