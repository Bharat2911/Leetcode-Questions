class Solution {
public:
    string solve(string&s)
    {
        stack<char>st;
        string ans;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size()>0)
                {
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        
        //stack implimentation
        string s1=solve(s);
        string s2=solve(t);
        
        if(s1==s2)return true;
        return false;
        
    }
};