class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //brute force sort and find
        
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        return nums[k-1];
        
    }
};