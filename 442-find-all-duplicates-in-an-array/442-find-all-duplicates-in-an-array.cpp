class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>ans;
        
        for(auto itr:nums)
        {
            itr=abs(itr);
            
            if(nums[itr-1]>0)
            {
                //element occuring first time
                nums[itr-1]*=-1;
            }
            else
            {
                // elemnt occuring the second time
                 ans.push_back(itr);
            }
        }
        
        return ans;
    }
};