class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //wqull using the dequeue and store index in the sdecreasing manner of gretaert to smaller
        //so when ever elment come check from back if the elemnt is smaller then remove 
        //check from front if the elemnt is out of bound then rfemofve 
        
        
        deque<int>dq;
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            //remove the out of bound element
            
            if(!dq.empty() and dq.front()==i-k)
            {
                dq.pop_front();
            }
            
            //and if we get the smaller elemnt then current element than also remove
            while(!dq.empty() and nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
            
            //if window size hit we give get the max at front of queue since we are storing in 
            //decreasing fashion
            if(i>=k-1 )
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};