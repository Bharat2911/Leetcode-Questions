class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        
        int n=s1.length();
        
        int m=s2.length();
        
        int i=0;
        
        int j=0;
        
        string ans="";
        
        while(i<n and j<m)
        {
            ans+=s1[i];
            
            ans+=s2[j];
            
            i++;
            j++;
        }
        
        while(i<n)
        {
            ans+=s1[i];
            i++;
        }
        
        while(j<m)
        {
            ans+=s2[j];
            
            j++;
        }
        
        return ans;
    }
};