class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n=s.length();
        
        stack<char>st;
        
        int count=0;
        
        for(auto itr:s)
        {
            if(itr=='(')
            {
                st.push(itr);

            }
            else if(itr==')' and !st.empty())
            {
                st.pop();
            }
            else if(itr==')' and st.empty())
            {
                count++;
            }
        }
        while(!st.empty())
        {
            st.pop();
            count++;
        }
        return count;
    }
};