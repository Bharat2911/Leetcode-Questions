class Solution
{
    public:
        int calculate(string s)
        {

           int n = s.length();

            int digit = 0;
            int sign = +1;
            int ans = 0;

            stack<int> st;

            for (int i = 0; i < n; i++)
            {

               	//integer
                if (s[i] >= '0'
                    and s[i] <= '9')
                {
                    digit = s[i] - '0';

                    while (i + 1 < n and(s[i + 1] >= '0'
                            and s[i + 1] <= '9'))
                    {
                        digit = digit *10 + (s[i + 1] - '0');
                        i++;
                    }

                    digit = digit * sign;
                    ans += digit;
                    digit = 0;
                    sign = +1;
                }
                else if (s[i] == '+')
                {
                    sign = +1;
                }
                else if(s[i]=='-')
                {
                    sign=-1;
                }
                else if(s[i]=='(')
                {
                    st.push(ans);
                    st.push(sign);
                    ans=0;
                    sign=+1;
                }
                else if(s[i]==')')
                {
                    int prev_sign=st.top();
                    st.pop();
                    
                    int num=st.top();
                    st.pop();
                    
                    ans=ans*prev_sign;
                    ans=ans+num;
                }
            }
            return ans;
        }
};