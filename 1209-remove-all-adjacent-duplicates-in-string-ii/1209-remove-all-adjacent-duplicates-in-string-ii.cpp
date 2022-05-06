class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.length();
        stack<pair<char,int>>st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty() || st.top().first!=s[i])
            {
                st.push({s[i],1});
            }
            else if(st.top().first==s[i])
            {
                st.top().second++;
                
                if(st.top().second==k)
                {
                    st.pop();
                }
            }
        }
        string ans;
        
        while(!st.empty())
        {
            char ch=st.top().first;
            int freq=st.top().second;
            st.pop();
            
            for(int i=0;i<freq;i++)
            {
                ans+=ch;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};