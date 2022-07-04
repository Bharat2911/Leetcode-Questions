class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        
        //usign the concept up=down+1
        //ans down=up+1;
        
        int up=0;
        int down=0;
        int ans=0;
        
        //in the end we will add one to our final answer becuse in each case we will include the first char
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])//up_hill case
            {
                up=down+1;
            }
            else if(nums[i]<nums[i-1])//down_hill case
            {
                down=up+1;
            }
        }
        
        ans=max(down,up);
        
        return ans+1;
        
    }
};