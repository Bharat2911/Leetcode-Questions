class Solution
{
    public:
       	//we will be using the simple idea that 
        int mctFromLeafValues(vector<int> &arr)
        {

            int n = arr.size();

            stack<int> st;

            int sum = 0;

            for (auto itr: arr)
            {
                while (!st.empty() and itr > st.top())
                {
                    int top = st.top();
                    st.pop();

                    if (st.empty()) sum += top * itr;

                    else
                    {
                        sum += top* min(st.top(), itr);
                    }
                }
                //else push the current character in any other cases
                st.push(itr);
                
            }

           	//ab ek baar aur stack se nikal ke karo to get the answer
            while (!st.empty())
            {
                int top = st.top();
                st.pop();

                if (!st.empty()) sum += top *st.top();
            }

            return sum;

           	//T.C -> O(n);..since itrating over the array only once

           	//S.C -> O(n);//using the stack
        }
};