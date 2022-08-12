class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //mid->0 swao(low,mid)low++ mid++
        //mid->1  mid++
        //mid->2 swap(mid,high)high--
        
        int n=nums.size();
        
        int mid=0;
        int low=0;
        
        int high=n-1;
        
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};