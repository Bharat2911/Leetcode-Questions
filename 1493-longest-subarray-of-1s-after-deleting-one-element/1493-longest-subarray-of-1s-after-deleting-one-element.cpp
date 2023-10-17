class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
         int j=0,i=0;
        int maxi=0;
        int one=0;
        int zero=0;
        while(j<nums.size()){
            if(nums[j]==0)
                zero++;
            else
                one++;
             maxi=max(maxi,one);
            if(zero==0)
                maxi=max(maxi,one)-1;
            if(zero==1)
              maxi=max(maxi,one);
            else{
                while(zero>1)
                {
                    if(nums[i]==1)
                        one--;
                    else
                        zero--;
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};