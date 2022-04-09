class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>map;
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        vector<int>ans;
        
        for(auto m:map)
        {
            if(m.second==1)
            {
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};