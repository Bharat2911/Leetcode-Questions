class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        
        int n=nums.size();
        
        int idx=0;
        int count=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++)
        {
            if(nums[i][0]<nums[idx][1])
            {
                count++;
                
                if(nums[idx][1]>nums[i][1])
                {
                    idx=i;
                }
            }
            else
            {
                idx=i;
            }
        }
        return count;
    }
};