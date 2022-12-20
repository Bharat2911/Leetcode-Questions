class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //approach 1->linear searching 
        //O(n)
        //O(1)
        
//         int n=nums.size();
        
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==target)
//             {
//                 return i;
//             }
//         }
//         return -1;
        
        //approach 2->binary search 
        //O(log n)
        //O(1)
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            //we have two cases either we have left sorted array or we have right sorted array
            else if(nums[mid]>=nums[low])
            {
                //left sorted array
                if(target>=nums[low] and target<nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                //right sorted array
                if(target>nums[mid] and target<=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};