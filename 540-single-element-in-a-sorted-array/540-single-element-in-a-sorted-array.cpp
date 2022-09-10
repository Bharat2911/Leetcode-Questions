class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int>map;
        
        for(int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        
        for(auto itr:map)
        {
            if(itr.second==1)
            {
                return itr.first;
            }
        }
        return -1;
    }
};