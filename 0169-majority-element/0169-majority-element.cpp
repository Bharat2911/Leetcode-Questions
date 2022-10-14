class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //T.C=O(n)
        //S.C=O(n)
        
//         int n=nums.size();
        
//         unordered_map<int,int>map;
        
//         for(auto itr:nums)
//         {
//             map[itr]++;
//         }
        
//         for(auto itr:map)
//         {
//             if(itr.second>n/2)
//             {
//                 return itr.first;
//             }
//         }
//         return -1;
        int n=nums.size();
        
        int prev=0;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(count==0)prev=nums[i];
            
            if(prev==nums[i])count++;
            
            else count--;
        }
        return prev;
    }
};