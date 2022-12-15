class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //sliding window +hash_map
        
        int n=s1.length();
        
        int m=s2.length();
        
        if(n>m)return false;
        vector<int>for_s1(26,0);
        vector<int>for_s2(26,0);
        
        int i=0;
        int j=0;
        
        
        while(j<n)
        {
            for_s1[s1[j]-'a']++;
            for_s2[s2[j]-'a']++;
            j++;
        }
        j-=1;
        
        while(j<m)
        {
            if(for_s1==for_s2)
            {
                return true;
            }
            j++;
            if(j!=m)
            {
                for_s2[s2[i]-'a']--;
                for_s2[s2[j]-'a']++;
                i++;
            }
        }
        return false;
    }
};