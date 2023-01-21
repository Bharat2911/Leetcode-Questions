class Solution {
public:
    string customSortString(string order, string s) {
        
        vector<char> cnt(128,0);
        string ans="";
        for(auto &c:s)
        {
            cnt[c]++;
        }
        for(auto &c:order)
        {
            while(cnt[c]>0)
            {
                ans+=c;
                cnt[c]--;
            }
        }
        for(char c='a';c<='z';c++) // for remaining alphabate which
        {                          //is not in order
            while(cnt[c]>0)
            {
                ans+=c;
                cnt[c]--;
            }
        }
        return ans;
        
    }
};