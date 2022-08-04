class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
        
        //we have to find the distance of 1 from all cell and return the max distance
          int row=mat.size();
        int col=mat[0].size();
        
        vector<vector<int>>ans(row,vector<int>(col,INT_MAX));
        
        //queue for bfs
        int count_zero=0;
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==1)
                {
                    ans[i][j]=0;
                    //multi source bfs
                    q.push({i,j});
                }
                else
                {
                    count_zero++;
                }
            }
        }
        if(count_zero==0)return -1;
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=i+dx[idx];
                int newj=j+dy[idx];
                
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and ans[i][j]+1<ans[newi][newj])
                {
                    ans[newi][newj]=1+ans[i][j];
                    q.push({newi,newj});
                }
            }
        }
        int ma=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ma=max(ma,ans[i][j]);
            }
        }
        if(ma==INT_MAX)return -1;
        return ma;
    }
};