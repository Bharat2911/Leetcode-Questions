class Solution {
public:
    int dist(int p1,int p2)
    {
        return (p1*p1)+(p2*p2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(auto itr:points)
        {
            int u=itr[0];
            int v=itr[1];
            
            int x=dist(u,v);
            
            pq.push({x,{u,v}});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        vector<vector<int>>ans;
        
        while(!pq.empty())
        {
            int top=pq.top().first;
            
            int p1=pq.top().second.first;
            
            int p2=pq.top().second.second;
            
            pq.pop();
            
            ans.push_back({p1,p2});
        }
        
        return ans;
    }
};