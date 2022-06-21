class Solution {
public:
    bool solve(int index,int i,int j,vector<vector<char>>&board,string&word,vector<vector<bool>>&vis)
    {
        //base case
        if(index==word.length())
        {
            return true;
        }
        int row=board.size();
        int col=board[0].size();
        
        //itrate in the four direction and check 
        int dx[4]={0,1,0,-1};
        
        int dy[4]={1,0,-1,0};
        
        vis[i][j]=true;
        
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj]  and board[newi][newj]==word[index])
            {
                if(solve(index+1,newi,newj,board,word,vis))
                {
                    return true;
                }
            }
        }
        
        vis[i][j]=false;//back traking stepto try all [possble way]
        
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int row=board.size();
        int col=board[0].size();
        
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                    if (solve(1,i,j,board,word,vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};