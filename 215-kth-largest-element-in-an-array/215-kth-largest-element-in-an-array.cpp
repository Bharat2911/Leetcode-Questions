class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //brute force sort and find
        
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        return nums[k-1];
        
        // T.c=O(N log n)
        // S.C =O(1);
        
        
        
        //optimised using the heap
        
        //max heap
        priority_queue<int>pq;
        
        for(auto itr:nums)
        {
            pq.push(itr);
        }
        
        k--;
        
        while(!pq.empty() and k>0)
        {
            pq.pop();
            
            k--;
        }
        
        return pq.top();
        
        
        //T.c ==O(n log k)
        //S.C ==o(n);
        
        
    }
};