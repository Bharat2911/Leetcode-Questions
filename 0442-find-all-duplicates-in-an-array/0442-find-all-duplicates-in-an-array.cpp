class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        //brute force->sorting
        //T.C=O(nlogn)
        //S.C=O(1);
        
//         sort(nums.begin(),nums.end());
        
//         vector<int>ans;
        
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 ans.push_back(nums[i]);
//             }
//         }
        
//         return ans;
        
       
        //optimisation->using map (hashing)
        
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
        
        
        //most optimised
        //first time element seen hoga usko negative kar do yahi approach hai my friend
        
        //T.C=O(n)
        //S.c=O(1);
        
        vector<int>ans;
        for(auto itr:nums)
        {
            itr=abs(itr);
            
            if(nums[itr-1]>0)
            {
                nums[itr-1]*=-1;
            }
            else
            {
                ans.push_back(itr);
            }
        }
        return ans;
        
       
    }
};