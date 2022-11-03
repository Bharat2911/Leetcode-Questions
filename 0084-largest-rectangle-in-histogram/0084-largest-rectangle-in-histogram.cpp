class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //teo cheez we need 
        //next smaller ka index
        //previous smaller ka index
        
        stack<int>st;//(stack will be storing the index)
        
        int n=heights.size();
        
        vector<int>left(n);//this is storing the previous smaller
        
        vector<int>right(n);//this is storing the next smaller
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            
           if(st.empty())
           {
               left[i]=-1;
           }
            else
            {
                left[i]=st.top();
            }
            st.push(i);
            
        }
        //stack ko phir se empty kar dena hia
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and heights[i]<=heights[st.top()])
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