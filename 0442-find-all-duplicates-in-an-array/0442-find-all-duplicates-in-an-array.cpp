class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        //brute force->sort
        //T.C=O(nlogn)
        //S.C=O(1);
        
        sort(nums.begin(),nums.end());
        
        vector<int>ans;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        //using map man
        
        //T.C=O(n);
        //S.C=O(n);
        
//         unordered_map<int,int>map;
        
//         for(auto itr:nums)
//         {
//             map[itr]++;
//         }
        
//         vector<int>ans;
        
//         for(auto itr:map)
//         {
//             if(itr.second==2)
//             {
//                 ans.push_back(itr.first);
//             }
//         }
        
        
        
//         return ans;
    }
};