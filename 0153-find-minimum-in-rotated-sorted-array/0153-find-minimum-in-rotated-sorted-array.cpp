class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //approach 1->linear searching(O(n) and O(1))
        
        int n=nums.size();
        int ans=nums[0];
        
        for(auto itr:nums)
        {
            ans=min(ans,itr);
        }
        return ans;
        
    }
};