class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>sorted=nums;
        
        sort(sorted.begin(),sorted.end());
        
        if(sorted==nums)return 0;
        
        int x=0;
        int y=0;
        
        for(int i=0;i<n;i++)
        {
            if(sorted[i]!=nums[i])
            {
                x=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(sorted[i]!=nums[i])
            {
                y=i;
                break;
            }
        }
        return abs(y-x+1);
    }
};