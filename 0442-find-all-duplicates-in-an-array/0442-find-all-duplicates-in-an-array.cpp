class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        //using map man
        
        //T.C=O(n);
        //S.C=O(n);
        
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        vector<int>ans;
        
        for(auto itr:map)
        {
            if(itr.second==2)
            {
                ans.push_back(itr.first);
            }
        }
        
        
        
        return ans;
    }
};