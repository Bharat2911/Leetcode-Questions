class Solution
{
    public:
        int evalRPN(vector<string> &arr)
        {

            stack<long long> st;

            for (int i = 0; i < arr.size(); i++)
            {

                if (arr[i] == "+")
                {
                    long long x = st.top();
                    st.pop();

                    long long y = st.top();
                    st.pop();
                    st.push(y + x);
                }
                else if (arr[i] == "-")
                {
                    long long x = st.top();
                    st.pop();

                    long long y = st.top();
                    st.pop();
                    st.push(y - x);
                }
                else if (arr[i] == "*")
                {
                    long long  x = st.top();
                    st.pop();

                    long long y = st.top();
                    st.pop();
                    st.push(y *x);
                }
                else if (arr[i] == "/")
                {
                    long long x = st.top();
                    st.pop();

                    long long y = st.top();
                    st.pop();
                    st.push(y / x);
                }
                else
                {
                    st.push(stoi(arr[i]));
                }
            }
            return st.top();
        }
};