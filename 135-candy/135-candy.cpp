class Solution {
public:
    int candy(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>ans_l(n,1);
        vector<int>ans_r(n,1);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1] )
            {
                ans_l[i]=ans_l[i-1]+1;
                
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1] )
            {
                ans_r[i]=ans_r[i+1]+1;
            }
        }
        int sum=0;
       for(int i=0;i<n;i++)
       {
           sum+=max(ans_l[i],ans_r[i]);
       }
        
        return sum;
    }
};