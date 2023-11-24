class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();
        
        int low=0;
        
        int mid=0;
        
        int high=n-1;
        
        
        while(mid<=high)
        {
            //case 1
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            
            //case 2
            else if(nums[mid]==1)
            {
                mid++;
            }
            //case 3
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};