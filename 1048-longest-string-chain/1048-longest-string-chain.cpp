class Solution {
public:
    static bool comp(string&s1,string&s2)
    {
        return s1.length()<s2.length();
    }
    bool compare(string&s1 ,string &s2)
    {
        if(s1.length()!=s2.length()+1)return false;
        
        int count=0;
        int i=0;
        int j=0;
        //since string  s1 is greater than string s2
        
        while(i<s1.length())
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                count++;
                i++;
            }
        }
        if(count==1)return true;
        else return false;
    }
    int longestStrChain(vector<string>& s) {
        
        //smae as lis
        int n=s.size();
        
        vector<int>dp(n,1);
        //i have to sort it acc to the length
        
        sort(s.begin(),s.end(),comp);
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(s[i],s[j]) and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};