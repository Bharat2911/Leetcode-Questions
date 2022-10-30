class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        //approach ->we will think greedly
        //means jiska grow time jyada hai usko phele plant karenge apan
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<plantTime.size();i++)
        {
            pq.push({growTime[i],plantTime[i]});
        }
        
        int ans=0;
        int extra=0;
        
        while(!pq.empty())
        {
            int gt=pq.top().first;
            int pt=pq.top().second;
            pq.pop();
            
            ans=max(ans,gt+pt+extra+1);
            
            extra+=pt;
            
        }
        return ans-1;
    }
};