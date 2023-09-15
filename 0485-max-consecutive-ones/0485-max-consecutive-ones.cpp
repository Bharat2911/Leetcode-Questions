class Solution {
public:
    
    //T.C->O(n)
    //S.C->O(1)
    
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n=nums.size();
        
        int count=0;
        
        int ans=0;
            
        
        for(auto itr:nums)
        {
            if(itr==1)
            {
                count++;
                ans=max(ans,count);
            }
            else
            {
                count=0;
            }
        }
        return ans;
    }
};