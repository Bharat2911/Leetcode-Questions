class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //linear searching O(n) and o(1);
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
        }
        return -1;
    }
};