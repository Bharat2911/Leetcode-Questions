class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)return 0;
        
        int low=0;
        int high=n-1;
        
        // int ans=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(mid>0 and mid<n-1)
            {
                if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                {
                    // ans=mid;
                    return mid;
                }
                else if(nums[mid]<nums[mid-1])
                {
                    high=mid-1;
                }
                else if(nums[mid]<nums[mid+1])
                {
                    low=mid+1;
                }
            }
            else if(mid==0 )
            {
                if(nums[0]>nums[1])return 0;
                else return 1;
                
            }
            else if(mid==n-1)
            {
                if(nums[n-1]>nums[n-2])return n-1;
                else return n-2;
                
            }
        }
        return -1;
    }
};