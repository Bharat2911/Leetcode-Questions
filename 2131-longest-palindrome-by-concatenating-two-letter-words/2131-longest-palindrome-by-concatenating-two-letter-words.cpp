class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>map;
        
        int ans=0;
        
        for(auto itr:words)
        {
            string res=itr;
            
            reverse(res.begin(),res.end());
            
            if(map[res]>0)
            {
                //reverse is present man
                
                ans+=4;
                map[res]--;
            }
            else
            {
                map[itr]++;
            }

                
        }
        
        for(auto itr:map)
        {
            if(itr.first[0]==itr.first[1] and itr.second>0)
            {
                ans+=2;
                
                break;
            }
        }
        return ans;
    }
};