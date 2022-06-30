class Solution
{
    public:
        int minMoves(vector<int> &nums)
        {
           //find the minimum element in the array
            
            int mini=nums[0];
            
            for(int i=1;i<nums.size();i++)
            {
                mini=min(mini,nums[i]);
            }
            
            int ans =0;
            
            for(int i=0;i<nums.size();i++)
            {
                ans+=nums[i]-mini;
            }
            return ans;
        }
};