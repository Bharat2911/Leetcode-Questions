class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            if map size is less than total covered elemnets so far means we have the repetation.
            
            string  = "abc"
            
            total elemnet=3
            map.size()=3  (if we push this string in map and store the frequency)
            
            since map size is equal to total ele hence no repetation is there
            
            string ="aab"
            total element=3
            map.size()=2
            
            map size if less than total ele means there is repetation
            
            
            
         
        */
        //so we will be using the concept of sliding window
        int n=s.length();
        
        int i=0;
        int j=0;
        
        unordered_map<char,int>map;
        
        int ans=0;
        
        while(j<n)
        {
            map[s[j]]++;
            
            while(map.size()<j-i+1)
            {
                //repetation is therir so shink the window
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