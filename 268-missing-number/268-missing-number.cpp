class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        //t.c-> O(n);
        //s.c->O(n);
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        int ans=0;
        
        for(int i=0;i<=n;i++)
        {
            if(map.find(i)==map.end())
            {
                ans=i;
                break;
            }
        }
        return ans;
        
      
    }
};