class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>map;
        
        int sum=0;
        
        map[0]=1;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
           sum+=nums[i];
            
           sum=(k+(sum%k))%k;
            
            if(map.find(sum)!=map.end())
            {
                count+=map[sum];
            }
            map[sum]++;
        }
        return count;
    }
};