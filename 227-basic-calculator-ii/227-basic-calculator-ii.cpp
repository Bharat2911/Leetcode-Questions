class Solution {
public:
     bool isop(char c)
    {
        if(c=='+' || c=='-' || c=='*' || c=='/')return true;
        return false;
        
    }
    int calculate(string s) {
     
        int n=s.length();
        int curr_num=0;
        char prev_op='+';
        stack<int>st;
        
        
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            
            if(ch>='0' and ch<='9')//means if there is digit then form the number
            {
                curr_num=curr_num*10+(ch-'0');
            }
             if(isop(ch) || i==n-1)
            {
                if(prev_op=='+')
                {
                    st.push(curr_num);
                }
               else if(prev_op=='-')
                {
                    st.push(-curr_num);
                }
               else if(prev_op=='*')
                {
                   int top=st.top();
                   st.pop();
                   
                    st.push(top*curr_num);
                }
                if(prev_op=='/')
                {
                    int top=st.top();
                    st.pop();

                    st.push(top/curr_num);
                }
                
                prev_op=ch;
                curr_num=0;
            }

                
        }
        int ans=0;
        while(!st.empty())
        {
           int top=st.top();
            st.pop();
            ans+=top;
            
        }
        return ans;
    }
};