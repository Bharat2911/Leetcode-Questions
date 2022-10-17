class Solution {
public:
    //approch to sahi hai dry run to sahi ho rha hai
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>ans;
        
        int n=s.length();
        
        int k=p.length();//ye meri window ka size  bhi hoga
        
        if(k>n)
        {
            return {};
        }
        
        int i=0;
        int j=0;
        // int x=0;//this is use to fill the freq array for p
        
        vector<int>for_s(26,0);
        
        vector<int>for_p(26,0);
        
        while(j<k)
        {
            for_s[s[j]-'a']++;
            for_p[p[j]-'a']++;
            j++;
        }
        j-=1;
        
        while(j<n)
        {
            if(for_s==for_p)
            {
                ans.push_back(i);
            }
            j++;
            if(j!=n)
            {
                for_s[s[j]-'a']++;
                
                for_s[s[i]-'a']--;
                
                i++;
            }
        }
        return ans;
    }
};