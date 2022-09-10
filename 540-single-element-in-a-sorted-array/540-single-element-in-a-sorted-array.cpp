class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
//         int n=nums.size();
        
//         unordered_map<int,int>map;
        
//         for(int i=0;i<n;i++)
//         {
//             map[nums[i]]++;
//         }
        
//         for(auto itr:map)
//         {
//             if(itr.second==1)
//             {
//                 return itr.first;
//             }
//         }
//         return -1;
        
        //optimise the above solution by binary searchg
        
        int n=nums.size();
        
        int low=0;
        
        int high=n-2;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==nums[mid^1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return nums[low];
    }
};