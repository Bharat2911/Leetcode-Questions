class Solution
{
    public:
        int longestValidParentheses(string s)
        {

           	//wil do two itrations keep the count of open and close parenthesisi
            int n = s.length();

            int open = 0;
            int close = 0;
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    open++;
                }
                else
                {
                    close++;
                }
                if (open == close)
                {
                    ans = max(ans, 2 *open);
                }
                else if (close > open)
                {
                    open = 0;
                    close = 0;
                }
            }
            open = 0;
            close = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '(')
                {
                    open++;
                }
                else
                {
                    close++;
                }
                if (open == close)
                {
                    ans = max(ans, 2 *open);
                }
                else if (open > close)
                {
                    open = 0;
                    close = 0;
                }
            }

            return ans;
        }
};