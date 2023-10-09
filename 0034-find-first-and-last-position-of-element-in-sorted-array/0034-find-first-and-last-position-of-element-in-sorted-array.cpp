class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //approach 1->linear searching we will do here
        //approch 2->we can do this using the binary searching
        
//         int n=nums.size();
        
//         vector<int>ans;
        
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==target)
//             {
//                 ans.push_back(i);
//                 break;
//             }
            
//         }
//         if(ans.size()==0)
//         {
//             ans.push_back(-1);
//         }
        
//         for(int i=n-1;i>=0;i--)
//         {
//             if(nums[i]==target)
//             {
//                 ans.push_back(i);
//                 break;
//             }
//         }
//         if(ans.size()==1)
//         {
//             ans.push_back(-1);
//         }
        
//         return ans;
        
        //approach 2
        
        int n=nums.size();
        
        vector<int>ans(2);
        
         bool p=binary_search(nums.begin(), nums.end(), target);
        
        if(!p)
        {
            return {-1,-1};
        }
        int lower=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        int upper=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        upper=upper-1;
        
        
        ans[0]=lower;
        
        ans[1]=upper;
        
        
        return ans;
        
    }
};