class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        //we will be using the sliding window here
        int n=nums.size();
        
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        
        unordered_map<int,int>map;
        
        while(j<n)
        {
            map[nums[j]]++;
            sum+=nums[j];
            
            while(map.size()<j-i+1)
            {
                //shrink the window here
                map[nums[i]]--;
                sum-=nums[i];
                
                if(map[nums[i]]==0)
                {
                    map.erase(nums[i]);
                }
                i++;
            }
            
            if(map.size()==j-i+1)//we will be getting our anser
            {
                ans=max(ans,sum);
            }
            j++;
        }
        return ans;
    }
};