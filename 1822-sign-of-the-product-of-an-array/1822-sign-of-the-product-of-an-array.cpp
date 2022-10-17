class Solution {
public:
    //T.C=O(n)
    //S.C=O(1)
    int arraySign(vector<int>& nums) {
        
        int count_neg=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                return 0;
            }
            
            if(nums[i]<0)
            {
                count_neg++;
            }
        }
        if(count_neg&1)return -1;
        
        else return 1;
    }
};