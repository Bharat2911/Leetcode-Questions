class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //approach 1->usning map
        
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            if(itr.second>=2)
            {
                return itr.first;
            }
        }
        return -1;
    }
};