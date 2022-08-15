class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //we can also do this using the cycle detection method
        int n=nums.size();
        
        int slow=nums[0];
        int fast=nums[0];
        
        while(true)
        {
            fast=nums[nums[fast]];//move by two
            slow=nums[slow];//move by one
            
            if(fast==slow)
            {
                fast=nums[0];
                
                while(fast!=slow)
                {
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return fast;
            }
        }
        
    }
};