class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>nums;
        
        for(auto itr:nums1)
        {
            nums.push_back(itr);
        }
        
        for(auto itr:nums2)
        {
            nums.push_back(itr);
        }
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        if(n&1)
        {
            int m=n/2;
            
            return nums[m];
        }
        else
        {
            int m=n/2;
            
            return (nums[m-1]+nums[m])/2.0;
        }
        
    }
};