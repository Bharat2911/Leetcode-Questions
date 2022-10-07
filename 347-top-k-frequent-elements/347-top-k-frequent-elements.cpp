class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>map;
        
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        for(auto itr:map)
        {
            pq.push({itr.second,itr.first});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        for(int i=0;i<k;i++)
        {
            int top=pq.top().second;
            pq.pop();
            
            ans.push_back(top);
        }
        return ans;
    
    }
};