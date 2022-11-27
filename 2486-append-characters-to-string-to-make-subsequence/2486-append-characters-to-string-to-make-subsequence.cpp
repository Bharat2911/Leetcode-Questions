class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        int i=0;
        int j=0;
        
        int count=0;
        
        
        while(i<n)
        {
            if(s[i]==t[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                
                i++;
            }
        }
        return m-count;
    }
};