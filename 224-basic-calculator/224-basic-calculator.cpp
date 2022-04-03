class Solution {
public:
    int calculate(string s) {
         int n=s.length();
        
        stack<int>st;
        
        int sign=+1;
        long long curr_num=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))//means if it is a integer
                
            {
                 curr_num=s[i]-'0';
                
                while(i+1<n and isdigit(s[i+1]) )//jab tak integr mile usko number banate jao
                {
                    curr_num=curr_num*10+(s[i+1]-'0');
                    i++;
                }
                //couple of basic steps
                curr_num=curr_num*sign;
                ans+=curr_num;
                curr_num=0;
                sign=+1;
            }
            else if(s[i]=='+')
            {
                sign=+1;
            }
            else if(s[i]=='-')
            {
                sign=-1;
                
            }
            else if(s[i]=='(')//this is the core step
            {
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=+1;
            }
            else if(s[i]==')')//pop out steps
            {
                int prev_sign=st.top();
                st.pop();
                
                int prev_ans=st.top();
                st.pop();
                
                ans=ans*prev_sign;
                ans=ans+prev_ans;
                
            }
        }
        return ans;
    
    }
};