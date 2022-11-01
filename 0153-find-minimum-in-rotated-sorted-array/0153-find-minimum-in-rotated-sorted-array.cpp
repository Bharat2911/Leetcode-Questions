class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        
        int ans=INT_MAX;
        
        for(auto itr:nums)
        {
            ans=min(ans,itr);
        }
        return ans;
    }
};