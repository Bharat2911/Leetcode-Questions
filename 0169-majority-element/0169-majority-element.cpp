class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //T.C=O(n)
        //S.C=O(n)
        
        int n=nums.size();
        
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            if(itr.second>n/2)
            {
                return itr.first;
            }
        }
        return -1;
    }
};