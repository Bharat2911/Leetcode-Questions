class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        //pq ->{current max_sum,index}
        
        priority_queue<pair<int,int>>pq;
        
        int n=nums.size();
        
        pq.push({nums[0],0});
        
        int max_sum=nums[0];
        
        for(int i=1;i<n;i++)
        {
            
            while(i-pq.top().second>k)
            {
                pq.pop();
            }
            
            int curr=pq.top().first;
            
            max_sum=curr+nums[i];
            
            pq.push({max_sum,i});

        }
        return max_sum;
    }
};