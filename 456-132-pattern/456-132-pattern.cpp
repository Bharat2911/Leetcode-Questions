class Solution {
public:
    //most optimised 
 //   tc ->O(n)
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
            
        vector<int>left_min(n);
        stack<int>st;
        
        
        left_min[0]=nums[0];
       
        
        for(int i=1;i<n;i++)
        {
            left_min[i]=min(left_min[i-1],nums[i]);
        }
        for(int j=n-1;j>=0;j--)
        {
            if(nums[j]>left_min[j])
            {
                while(!st.empty() and st.top()<=left_min[j])
                    st.pop();
                if(!st.empty() and st.top()<nums[j])
                    f=true;
                
                st.push(nums[j]);
            }
        }
        return f;
    }
};