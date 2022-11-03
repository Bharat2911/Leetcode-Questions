class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>map;
        
        int ans=0;
        
        for(auto itr:words)
        {
            string res=itr;
            
            reverse(res.begin(),res.end());
            
            if(map[res]>0)//measn map me reverse present hia
            {
                ans+=4;
                
                map[res]--;
            }
            else
            {
                map[itr]++;
                //reveres present nahi hai to daal do current element
            }
        }
        //now case of already palindrome
        for(auto itr:map)
        {
            if(itr.first[0]==itr.first[1] and itr.second>0)
            {
             
                return ans+2;
                
                
            }
        }
        return ans;
    }
};