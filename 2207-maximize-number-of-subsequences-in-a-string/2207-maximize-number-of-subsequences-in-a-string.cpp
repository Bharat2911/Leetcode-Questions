class Solution {
public:
    long long solve(string&s,string&p)
    {
         int n=s.length(); 
        
         long long ans=0;
        unordered_map<char,long long>map;
        
        for(auto itr:s)
        {
            if(itr==p[1])
            {
                ans+=map[p[0]];
            }
            map[itr]++;
        }
        return ans;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        
        //pattern ka second hamesha end me lagao aur pattern ka first char hamesha starting me to get maximum answer
        //T.C=O(n)//linearly itrating
        //S.C=O(n)//using the map
        
        string str1=text+pattern[1];//O(1)
        
        string str2=pattern[0]+text;//O(1)
        
        long long ans1=solve(str1,pattern);//O(n),O(n)
        long long ans2=solve(str2,pattern);//O(n),O(n)
        
        return max(ans1,ans2);
    }
};