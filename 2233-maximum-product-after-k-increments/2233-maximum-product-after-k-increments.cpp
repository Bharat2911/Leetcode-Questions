class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        // /everytie i have to pick the smalller elemnt and increment it by one
        //so we will be using the min heap here()
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int mod = 1e9 + 7;
        for(auto itr:nums)
        {
            pq.push(itr);
        }
        
        while(k-- >0)
        {
            int top=pq.top();
            pq.pop();
            top=top+1;
            
            pq.push(top);
        }
        long long ans=1;
        
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            
            ans=(ans*top)%mod;
        }
        return ans;
    }
};