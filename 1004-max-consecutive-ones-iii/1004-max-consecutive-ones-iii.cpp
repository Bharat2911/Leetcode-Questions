class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        //this is the sliding window boys
        int n=nums.size();
        
        int count_zero=0;
        
        int ans=0;
        
        int i=0;
        
        int j=0;
        
        while(j<n)
        {
            if(nums[j]==0)
            {
                count_zero++;
            }
            
            while(count_zero>k)
            {
                //shrink the window idhar se
                if(nums[i]==0)
                {
                    count_zero--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};