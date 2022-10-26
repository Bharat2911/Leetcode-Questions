class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>map;
        
        int count=0;
        int sum=0;
        
        map[0]=1;
        
        for(auto itr:nums)
        {
            sum+=itr;
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