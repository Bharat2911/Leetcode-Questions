class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        //doing the linear itration
        int n=nums.size();
        
        int idx=0;
        
        //base case here we have to add
        if(n==1)
        {
            return 0;
            
        }
        
        for(int i=0;i<n;i++)
        {
            //handel the case of corner elemnet here
            if(i==0)
            {
                if(nums[i]>nums[i+1])
                {
                    idx=i;
                }
            }
           else if(i==n-1)
            {
                if(nums[i]>nums[i-1])
                {
                    idx=i;
                }
            }
           else if(nums[i]>nums[i-1] and nums[i]>nums[i+1])
            {
                idx=i;
                
            }
        }
        return idx;
    }
};