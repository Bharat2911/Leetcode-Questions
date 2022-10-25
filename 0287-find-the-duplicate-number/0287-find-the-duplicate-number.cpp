class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //brute force
        
        //sort kar du then itrate and find
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return nums[i];//since that is my duplicate
            }
        }
        return -1;
    }
};