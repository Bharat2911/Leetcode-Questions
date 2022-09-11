class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
          unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        int ans=0;
        int x=-1;
        
        for(auto itr:map)
        {
            if(itr.first%2==0)
            {
                if(itr.second>ans)
                {
                    ans=itr.second;
                    x=itr.first;
                }
                if(itr.second==ans)
                {
                    if(itr.first<x)
                    {
                        x=itr.first;
                    }
                }
            }
            
        }
            return x;
        
    
    
    }
};