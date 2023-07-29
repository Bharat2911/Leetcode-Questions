class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        int n=nums.size();
        
        unordered_map<int,int>map;
        
        vector<int>ans;
        
        
        //map.find()==map.end()//means not present in the map
        for(int i=0;i<n;i++)
        {
            if(map.find(target-nums[i])!=map.end())//means present in map
            {
                ans.push_back(map[target-nums[i]]);
                
                ans.push_back(i);
            }
            
            map[nums[i]]=i;
        }
        
        return ans;
    }
};