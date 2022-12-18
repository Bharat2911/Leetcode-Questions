class Solution {
public:
    int nextGreaterElement(int nn) {
        
        string nums=to_string(nn);
        
        string str=nums;
        
          int n=nums.length();
        
        int i,j;
        
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(j=n-1;j>=0;j--)
            {
                if(nums[j]>nums[i])
                {
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
            
        }
        if(nums<=str)return -1;
        long long ans=stoll(nums);
        
        if(ans>INT_MAX || ans<INT_MIN)return -1;
        return ans;
    }
};