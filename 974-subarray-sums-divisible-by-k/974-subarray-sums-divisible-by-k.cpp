class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        //doing this usingt he map
        unordered_map<int,int>map;
        
        int sum=0;
        int count=0;
        // map[sum]=1;
        map[0]=1;
        
        
        for(int i=0;i<nums.size();i++)
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