class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        //we will be using the max heap;
        
        priority_queue<int>pq;
        
        for(auto itr:nums)
        {
            pq.push(itr);
        }
        
        int ans=0;
        
        while(!pq.empty() and k>0)
        {
            int top=pq.top();
            pq.pop();
            k--;
            if(top&1)
            {
                top=top/2;
                top=top+1;
            }
            else
            {
                top=top/2;
            }
            pq.push(top);
        }
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            
            ans+=top;
            
        }
        return ans;
    }
};