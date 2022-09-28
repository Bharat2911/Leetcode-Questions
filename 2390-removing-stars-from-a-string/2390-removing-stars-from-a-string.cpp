class Solution {
public:
    string removeStars(string s) {
        
        //we will be doing this using stack
        stack<char>st;
        
        for(auto itr:s)
        {
            if(itr=='*')
            {
                st.pop();
            }
            else
            {
                st.push(itr);
            }
             
        }
        string ans="";
        
        while(!st.empty())
        {
            char ch=st.top();
            st.pop();
            
            ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};