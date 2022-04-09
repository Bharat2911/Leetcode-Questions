class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n=temp.size();
        stack<int>st;//sack is storing the index
        vector<int>ans(n);
        ans[n-1]=0;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and temp[st.top()]<=temp[i])
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