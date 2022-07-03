class Solution {
public:
    string getHint(string s, string g) {
        
        vector<int>for_s(10,0);
        vector<int>for_g(10,0);
        
        int n=s.length();
        
        int bulls=0;
        int cows=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==g[i])
            {
                bulls++;
            }
            else
            {
                //update in vector
                for_s[s[i]-'0']++;
                for_g[g[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            cows+=min(for_s[i],for_g[i]);
        }
        
        string ans=to_string(bulls)+'A'+to_string(cows)+'B';
        
        return ans;
    }
};