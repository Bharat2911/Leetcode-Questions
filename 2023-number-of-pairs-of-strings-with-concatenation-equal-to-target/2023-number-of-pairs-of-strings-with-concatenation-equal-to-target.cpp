class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        
        //t>C=O(n^2)
        
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++ )
        {
            for(int j=0;j<n;j++)
            {
                if(nums[i]+nums[j]==target and i!=j)
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};