class Solution {
public:
    
    
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& vis)
    {
         int row=matrix.size();
        int col=matrix[0].size();
        
        if(vis[i][j]!=-1)return vis[i][j];
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        int count=1;
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            
            if(newi>=0 and newi<row and newj>=0 and newj<col  and matrix[newi][newj]>matrix[i][j])
            {
                
                
                count=max(count,1+solve(newi,newj,matrix,vis));
            }
        }
        return  vis[i][j]=count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        //simple dfs and dp
        int row=matrix.size();
        int col=matrix[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,-1));
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               
                   ans=max(ans,solve(i,j,matrix,vis));
                
            }
        }
        
        return ans;
    }
};