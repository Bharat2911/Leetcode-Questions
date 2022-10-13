class Solution {
public:
    int dist(int a,int b)
    {
        int x=a*a+b*b;
        
        return x;
        
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //use the priorty queue
        //t.C o(nlog k)
        //S.C O(k) //since every time priority queue is holding four elements 
        
        int n=points.size();
         //p/q -> {dist,{xi,yi}};
        
        priority_queue<pair<int,pair<int,int>>>pq;//max heap hi banao since we want the k min 
        
        for(int i=0;i<n;i++)
        {
            int u=points[i][0];
            
            int v=points[i][1];
            
            pq.push({dist(u,v),{u,v}});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        
        vector<vector<int>>ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};