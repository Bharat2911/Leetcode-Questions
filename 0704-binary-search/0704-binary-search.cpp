class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //brute force ->o(n),O(1) (linear searching)
        
//         int ans=-1;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==target)
//             {
//                 ans=i;
//             }
//         }
//         return ans;
        
        //approach->2 optimised O(log n)/O(1)
        //binary searching 
        
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
};