class Solution {
public:
    //T.C=O(n)
    //S.C=O(n)
    
    
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
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    count++;
                }
            }
        }
        while(!st.empty())
        {
            count++;
            st.pop();
        }
        
        return count;
    }
};