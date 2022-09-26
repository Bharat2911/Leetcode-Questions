class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {

            int n = heights.size();
            stack<int> st;

            int left[n];
            int right[n];

            for (int i = 0; i < n; i++)
            {
                while (!st.empty() and heights[st.top()] >= heights[i])
                {
                    st.pop();
                }

                if (st.empty())
                {
                    left[i] = -1;
                }
                else
                {
                    left[i] = st.top();
                }
                st.push(i);
            }
            
            //stack ko wapis se empty akr do taki next operatiosn ke liye use kar aaye
            while(!st.empty())
            {
                st.pop();
            }
            
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() and heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                
                if(st.empty())
                {
                    right[i]=n;
                }
                else
                {
                    right[i]=st.top();
                }
                
                st.push(i);
            }
            int ans=INT_MIN;
            
            for(int i=0;i<n;i++)
            {
                ans=max(ans,heights[i]*(right[i]-left[i]-1));
            }
            
            return ans;
        }
};