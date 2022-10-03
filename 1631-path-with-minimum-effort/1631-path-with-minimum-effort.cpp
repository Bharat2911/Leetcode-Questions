class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         //we will be doing this using dijsktra algorithm,n
        int row=heights.size();
        int col=heights[0].size();
        
        vector<vector<int>>distance(row,vector<int>(col,INT_MAX));
        
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       pq.push({0,{0,0}});
       distance[0][0]=0;
       
       int dx[4]={0,1,0,-1};
       int dy[4]={1,0,-1,0};
       
       while(!pq.empty())
       {
           int dist=pq.top().first;
           int i=pq.top().second.first;
           int j=pq.top().second.second;
           
           if(i==row-1 and j==col-1)
           {
               return dist;
           }
           pq.pop();
           
           for(int idx=0;idx<4;idx++)
           {
               int newi=i+dx[idx];
               int newj=j+dy[idx];
               
               if(newi>=0 and newi<row and newj>=0 and newj<col)
               {
                   int neweffort=max(abs(heights[newi][newj]-heights[i][j]),dist);
                   
                   if(neweffort<distance[newi][newj])
                   {
                       distance[newi][newj]=neweffort;
                       
                       pq.push({neweffort,{newi,newj}});
                   }
               }
           }
       }
       return 0;
    }
};