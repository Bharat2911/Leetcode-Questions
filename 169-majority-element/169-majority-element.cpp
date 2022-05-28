class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //t.c->o(n)
        //s.c->o(n);
        
        
        
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