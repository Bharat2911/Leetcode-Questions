class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        
        //for a particullar elemnet i have to find the previous smallest index and next smallest element index
        stack<int>st;//and stack will store the index here
        
        int n=height.size();
        
        int left[n];
        int right[n];
        
        
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.empty())left[i]=-1;
            else left[i]=st.top();
            
            st.push(i);
        }
        
        //now empty the stack so that we can gain use it in fingidn the nect smalles
        while(!st.empty())
        {
            st.pop();
        }
        
        
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.empty())right[i]=n;
            
            else right[i]=st.top();
            
            st.push(i);
        }
        int area=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            area=max(area,height[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};