class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int>map;
        int count=0;
        
        for(auto itr1:nums1)
        {
            for(auto itr2:nums2)
            {
                int sum_ab=itr1+itr2;
                
                map[sum_ab]++;//increase frequency of sum_ab
            }
        }
        
        for(auto itr3:nums3)
        {
            for(auto itr4:nums4)
            {
               int sum_cd=itr3+itr4;
                int sum_ab=-sum_cd;
                
               count+=map[sum_ab];
            }
        }
        return count;
    }
};