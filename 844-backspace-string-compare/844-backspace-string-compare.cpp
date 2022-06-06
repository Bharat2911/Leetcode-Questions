class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {

            int n1 = s.length();
            int n2 = t.length();

            stack<char> st1;
            stack<char> st2;

            for (int i = 0; i < n1; i++)
            {
                if (s[i] != '#')
                {
                    st1.push(s[i]);
                }
                else
                {
                    if(st1.size()>0)
                    {
                        st1.pop();
                    }
                    
                }
            }
            for (int i = 0; i < n2; i++)
            {
                if (t[i] != '#')
                {
                    st2.push(t[i]);
                }
                else
                {
                    if(st2.size()>0)
                    {
                        st2.pop();
                    }
                    
                }
            }
            string ans1 = "";
            string ans2 = "";
            while (!st1.empty())
            {
                char ch = st1.top();
                st1.pop();

                ans1.push_back(ch);
            }
            while (!st2.empty())
            {
                char ch = st2.top();
                st2.pop();

                ans2.push_back(ch);
            }
            if (ans1 == ans2)
            {
                return true;
            }
            return false;
        }
};