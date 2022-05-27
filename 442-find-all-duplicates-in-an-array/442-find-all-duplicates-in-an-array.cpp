class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // /using the map
        //o(n) o(n)
        //optimised o(n),O(1)
        //constant space me karo to optimised version hai ye
        int n=nums.size();
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        vector<int>ans;
        
        for(auto x:map)
        {
            if(x.second==2)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};