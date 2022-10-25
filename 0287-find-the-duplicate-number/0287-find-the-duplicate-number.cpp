class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        
        int slow=nums[0];
        int fast=nums[0];
        
        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            
            if(slow==fast)
            {
                fast=nums[0];
                
                while(slow!=fast)
                {
                    //ab ek stps se badhao dono ko
                    fast=nums[fast];
                    slow=nums[slow];
                    
                }
                return slow;
            }
        }
        return -1;
    }
};