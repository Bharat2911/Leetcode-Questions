class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //priority_queue se karenge bro jii oo jii wwaa jii
        unordered_map<int,int>map;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //coz want max = remove min
            
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
        
        vector<int>ans;
        
        for(int i=0;i<k;i++)
        {
            auto top=pq.top();
            pq.pop();
            
            ans.push_back(top.second);
        }
        return ans;
    }
};