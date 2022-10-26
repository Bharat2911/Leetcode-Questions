class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     
        int n=nums.size();
        
        unordered_map<int,int>map;
        
        map[0]=-1;//since zero bhi ek factor include karna hai
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(map.find(sum%k)!=map.end())
            {
                //if present in map and lefngth must be greater then equal to 2
                if(i-map[sum%k]>=2)
                {
                    return true;
                }
            }
            else
            {
                map[sum%k]=i;
            }
        }
         return false;
    }
};