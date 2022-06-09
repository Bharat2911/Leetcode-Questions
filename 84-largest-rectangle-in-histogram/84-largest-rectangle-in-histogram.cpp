class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        int n=arr.size();
        
        stack<int>st;
        
        int left[n];//store index of smaller number from left
        
        int right[n];//stor index of smaller number from right
        
        
        //first we will fill the left array
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            if(st.empty())left[i]=0;
            else left[i]=st.top()+1;//since convert to one based indexing 
            
            st.push(i);
        }
        
        //now wmpty the stack to use it for the filling of right array

        while(!st.empty())
        {
            st.pop();
        }
        
        //now fill thr right arrya
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            if(st.empty())right[i]=n-1;
            else right[i]=st.top()-1;
            
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,arr[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};