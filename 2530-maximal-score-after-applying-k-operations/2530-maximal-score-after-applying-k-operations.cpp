class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        //approach pick k max elemnts and apply operations on it 
        //for this we will be using the priority_queue as a data structure
        
        priority_queue<int>pq;
        long long ans=0;
        
        for(auto itr:nums)
        {
            pq.push(itr);
        }
        while(!pq.empty() and k>0)
        {
            int top=pq.top();
            pq.pop();
            
            ans+=top;
            
            long long add=0;
            if(top%3==0)
            {
                add=top/3;
                
            }
            else
            {
                add=(top/3)+1;
            }
            pq.push(add);
            k--;
        }
        return ans;
    }
};