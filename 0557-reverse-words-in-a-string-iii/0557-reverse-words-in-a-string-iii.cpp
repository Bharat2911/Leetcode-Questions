class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        string temp="";
        string res="";
        
        stack<char>st;
        
        for(auto itr:s)
        {
            st.push(itr);
        }
        
        while(!st.empty())
        {
            if(st.top()!=' ')
            {
                temp+=st.top();
                st.pop();
            }
            else
            {
                temp=st.top()+temp;
                st.pop();
                
                res=temp+res;
                temp="";
            }
        }
        res=temp+res;
        
        return res;
    }
};