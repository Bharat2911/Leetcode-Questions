class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        //will use the map
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            if(itr.second>1)
            {
                ans.push_back(itr.first);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(map[i]==0)
            {
                ans.push_back(i);
            }
        }
            
            
        
        return ans;
    }
};