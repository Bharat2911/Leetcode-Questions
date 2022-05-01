class Solution {
public:
    string removeDigit(string s, char digit) {
        
        int n=s.length();
        string ans;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==digit)
            {
                string temp=s.substr(0,i)+s.substr(i+1);
                
                ans=max(temp,ans);
            }
        }
        return ans;
        
    }
};