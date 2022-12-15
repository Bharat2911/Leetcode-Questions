class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //maintain an decreasing order in deque so that maximum always present at first
        int n=nums.size();
        
        deque<int>dq;
        
        vector<int>ans;
        
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() and dq.back()<nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            
            
        }
        ans.push_back(dq.front());
        
        for(int i=k;i<n;i++)
        {
            //current element should not present in the previous window
            if(dq.front()==nums[i-k])
            {
                dq.pop_front();
            }
            while(!dq.empty() and dq.back()<nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            
            ans.push_back(dq.front());
        }
        return ans;
    }
};