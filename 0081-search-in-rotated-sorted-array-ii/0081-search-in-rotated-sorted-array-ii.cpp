class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        //linear searching 
        //T.C->O(n)
        //S.C->O(1)
        
        for(auto itr:nums)
        {
            if(itr==target)
            {
                return true;
            }
        }
        return false;
    }
};