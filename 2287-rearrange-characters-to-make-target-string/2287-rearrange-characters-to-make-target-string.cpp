class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
        int n=s.length();
        
        int m=target.length();
        
        if(m>n)return 0;
        
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        
        for(auto itr:s)
        {
            m1[itr]++;
        }
        
        for(auto itr:target)
        {
            m2[itr]++;
        }
        
        int ans=INT_MAX;
        
        for(auto itr:m2)
            
        {
            ans=min(ans,m1[itr.first]/itr.second);
        }
        
        return ans;
        
    }
};