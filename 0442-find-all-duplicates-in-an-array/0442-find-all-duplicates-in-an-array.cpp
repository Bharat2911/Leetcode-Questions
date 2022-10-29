class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //negative mark karte jao simple 
        
        vector<int>ans;
        
        for(auto itr:nums)
        {
            itr=abs(itr);
            
            if(nums[itr-1]>0)
            {
                nums[itr-1]*=-1;
                
            }
            else
            {
                ans.push_back(itr);
            }
        }
        return ans;
    }
};