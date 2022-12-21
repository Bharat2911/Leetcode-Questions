class Solution {
public:
    string replaceDigits(string s) {
        
        int n=s.length();
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' and s[i]<='z')
            {
                ans+=s[i];
            }
            else
            {
                int idx=s[i-1]-'0';
                int curr_idx=idx+(s[i]);
                
                
                ans+=char(curr_idx);
            }
        }
        return ans;
    }
};