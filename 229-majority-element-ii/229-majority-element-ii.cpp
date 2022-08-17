class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        //T.C=o(n);
        //S.C=o(n);
        
        unordered_map<int,int>map;
        
        vector<int>ans;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            if(itr.second>nums.size()/3)
            {
               ans.push_back(itr.first);
            }
        }
        return ans;
        
    }
};