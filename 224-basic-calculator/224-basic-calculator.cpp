class Solution
{
    public:
        int calculate(string s)
        {

            int ans = 0;
            int curr_num = 0;
            int sign = +1;
            stack<int> st;

            for (int i = 0; i < s.length(); i++)
            {
                if (isdigit(s[i]))
                {
                    curr_num = s[i] - '0';

                    while (i + 1 < s.length() and isdigit(s[i + 1]))	//jab tak integr mile usko number banate jao
                    {
                        curr_num = curr_num *10 + (s[i + 1] - '0');
                        i++;
                    }
                    curr_num = curr_num * sign;
                    ans += curr_num;
                    curr_num = 0;

                    sign = +1;
                }
                else if (s[i] == '+')
                {
                    sign = +1;
                }
                else if (s[i] == '-')
                {
                    sign = -1;
                }
                else if (s[i] == '(')
                {
                    st.push(ans);
                    st.push(sign);
                    sign = +1;
                    ans = 0;
                }
                else if (s[i] == ')')
                {
                    int prev_sign = st.top();
                    st.pop();
                    int prev_ans = st.top();
                    st.pop();
                    ans = ans * prev_sign;
                    ans = ans + prev_ans;
                }
            }
            return ans;
        }
};