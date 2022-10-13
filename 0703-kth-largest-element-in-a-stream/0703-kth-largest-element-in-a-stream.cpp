class KthLargest {
public:
    //we will be doing this uing min heap
    //T.C=O(n log k)
    
    //S.C=O(n);
    
    priority_queue<int,vector<int>,greater<int>>pq;
    int xx;
    KthLargest(int k, vector<int>& nums) {
        
        int n=nums.size();
        xx=k;
        for(auto itr:nums)
        {
            pq.push(itr);
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        
        pq.push(val);
        
        if(pq.size()>xx)
        {
            pq.pop();
        }
        
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */