class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
        vector<int>ans(n);
        
        stack<int>st;
        
        ans[n-1]=0;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and temp[i]>=temp[st.top()])
            {
                st.pop();
            }
            
            int x=st.empty()?0:(st.top()-i);
            ans[i]=x;
            
            st.push(i);
        }
        
        return ans;
    }
};