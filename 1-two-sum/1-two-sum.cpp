class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // ****this is the kattar brute force approach****
//         int n=nums.size();
//         vector<int>ans;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     break;
//                 }
//             }
//         }
//         return ans;
        
        //optimising the above approach using the map
        unordered_map<int,int>map;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int count=target-nums[i];
            if(map.find(count)!=map.end())
            {
                if(i!=map[count])
                {
                      ans.push_back(i);
                ans.push_back(map[count]);
                break;
                }
               
            }
        }
        return ans;
    }
};