class Solution {
public:
    //this is backtraking
    bool solve(int idx,int i,int j,int row,int col,vector<vector<char>>&board,string&word,vector<vector<int>>&vis)
    {
        if(idx==word.length())
        {
            return true;
        }
        
        int dx[4]={0,1,0,-1};
        
        int dy[4]={1,0,-1,0};
        
        vis[i][j]=1;
        
        for(int z=0;z<4;z++)
        {
            int newi=i+dx[z];
            int newj=j+dy[z];
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and board[newi][newj]==word[idx]and !vis[newi][newj])
            {
                if(solve(idx+1,newi,newj,row,col,board,word,vis))
                {
                    return true;
                }
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        
        int row=board.size();
        int col=board[0].size();
        
        int idx=0;
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(1,i,j,row,col,board,word,vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};