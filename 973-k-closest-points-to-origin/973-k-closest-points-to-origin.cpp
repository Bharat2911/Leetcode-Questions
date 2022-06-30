class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //min heap 
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        
        //store the distance and index
        for(int i=0;i<points.size();i++)
        {
            double x=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            
            pq.push({x,i});
        }
        vector<vector<int>>ans;
        
       
        
        while(!pq.empty() and k>0)
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }
        
        
        return ans;
        
    }
};