class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        
        int count=1;
        
        //rather thnan sorting use the map that willl tackel the case of duplicates also
        
        map<int,int>map;//thsi store in sorted order itself
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            if(itr.first<1)continue;
            
            else if(itr.first!=count)return count;
            
            else count++;
        }
        
        return  count;
    }
};