class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //main motive maintaing decreasing order in deque
        
        int n=nums.size();
        
        deque<int>dq;
        
        vector<int>ans;
        
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() and nums[i]>dq.back())
            {
                dq.pop_back();
                
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        
        for(int i=k;i<n;i++)
        {
            //check current ele is not the ele of previous window
            
            if(dq.front()==nums[i-k])
            {
                dq.pop_front();
            }
            
            while(!dq.empty() and nums[i]>dq.back())
            {
                dq.pop_back();
                
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};