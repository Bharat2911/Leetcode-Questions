class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            if(itr.second>1)
            {
                return itr.first;
            }
        }
        return -1;
    }
};