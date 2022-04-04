class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int>map;
        int count=0;
        
        for(auto itr1:nums1)
        {
            for(auto itr2:nums2)
            {
                map[itr1+itr2]++;
            }
        }
        
        for(auto itr3:nums3)
        {
            for(auto itr4:nums4)
            {
                if(map.count(0-itr3-itr4))
                {
                    count+=map[0-itr3-itr4];
                }
            }
        }
        return count;
    }
};