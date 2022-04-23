class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int>map;
        
        for(auto itr1:nums1)
        {
             for(auto itr2:nums2)
             {
                int sum1=itr1+itr2;
                 map[sum1]++;
             }
        }
           int count=0;
        
        for(auto itr3:nums3)
        {
            for(auto itr4:nums4)
            {
               int  sum2=itr3+itr4;
                int sum1=-sum2;
                
                count+=map[sum1];
            }
        }
        return count;
                
    }
};