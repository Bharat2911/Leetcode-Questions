class Solution
{
    public:
        int evalRPN(vector<string> &s)
        {

            stack<int> st;

            for (auto itr: s)
            {

                if (itr == "+")
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 + x1);
                }
                else if (itr == "-")
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 - x1);
                }
                else if (itr == "/")
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 / x1);
                }
                else if (itr == "*")
                {
                    int x1 = st.top();
                    st.pop();
                    int x2 = st.top();
                    st.pop();
                    st.push(x2 *x1);
                }
                else
                {
                   	//we get num
                    st.push(stoi(itr));
                }
            }
            return st.top();
        }
};