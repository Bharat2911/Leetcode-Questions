class Solution {
public:
    //T.C=o(n)
    //S.C=o(k)//onlu k size pq i am using na
    int findKthLargest(vector<int>& nums, int k) {
        
        //using the priority_queue to solve this
        
        //making the min heap
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        
        for(auto itr:nums)
        {
            pq.push(itr);
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};