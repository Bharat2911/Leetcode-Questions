class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        
        int n=nums.size();
        int ans=0;
        
        if(n==2)
        {
            if(nums[1]>nums[0])return 1;
            else return 0;
        }
        
        if(n==1)
        {
            return 0;
        }
        
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1])
            {
                ans=i;
            }
            if(nums[n-1]>nums[n-2] and i==n-2)
            {
                ans=n-1;
            }
            // if(i==1 and nums[] )
        }
        //check karo for last element and for first element
        // if(nums[n-1]>nums[n-2] and )
        return ans;
    }
};