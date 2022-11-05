class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&res,int row,int col)
    {
        int count=0;
        
        int dx[8]={0,1,1,1,0,-1,-1,-1};
        int dy[8]={1,1,0,-1,-1,-1,0,1};
        
        for(int idx=0;idx<8;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and res[newi][newj]==1)
            {
                count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        //step 1->for each element in the grid count the negibhour live cell man
        
        int row=board.size();
        
        int col=board[0].size();
        
        vector<vector<int>>res=board;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int count=solve(i,j,res,row,col);//give the count of neighbour live cell
                
                cout<<count<<" ";
                
                if(res[i][j]==0)
                {
                    if(count==3)
                    {
                        board[i][j]=1;
                        
                    }
                }
                else
                {
                    if(count==2 || count==3)
                    {
                        board[i][j]=1;
                    }
                    else
                    {
                        board[i][j]=0;
                    }
                }
            }
        }
    }
};