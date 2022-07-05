class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        set<int>set;
        
        int n=nums.size();
        
        for(auto itr:nums)
        {
            set.insert(itr);
        }
        int ans=0;
        
        for(auto itr:nums)
        {
           
            
            if(!set.count(itr-1))
            {
                int curr=itr;
                int count=1;
                
                while(set.count(curr+1))
                {
                    curr++;
                    count++;
                }
                
                ans=max(ans,count);
            }
        }
        return ans;
    }
};