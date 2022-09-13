class Solution {
public:
    void solve(int i,int j,int source,vector<vector<int>>&image,int row,int col,int color)
    {
        int dx[4]={0,1,0,-1};
        
        int dy[4]={1,0,-1,0};
        
        queue<pair<int,int>>q;
        
        q.push({i,j});
        
        image[i][j]=color;
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            
            q.pop();
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=x+dx[idx];
                int newj=y+dy[idx];
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and image[newi][newj]==source)
                {
                    image[newi][newj]=color;
                    q.push({newi,newj});
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int row=image.size();
        int col=image[0].size();
        
        int source=image[sr][sc];
        
        int i=sr;
        int j=sc;
        
       if(image[sr][sc]!=color) solve(i,j,source,image,row,col,color);
        
        return image;
        
    }
};