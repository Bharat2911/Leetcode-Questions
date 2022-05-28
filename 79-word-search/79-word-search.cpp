class Solution
{
    public:
        bool solve(int i, int j, int idx, vector<vector < char>> &board, string &word,vector<vector<bool>>&vis)
        {
           	//base cases
            int row=board.size();
            int col=board[0].size();
            
            if (idx == word.size() ) return true;
            
            int dx[]={0,1,0,-1};
            int dy[]={1,0,-1,0};
            
            vis[i][j]=true;
            
            for(int x=0;x<4;x++)
            {
                int newi=i+dx[x];
                int newj=j+dy[x];
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and board[newi][newj]==word[idx])
                {
                    if(solve(newi, newj,idx+1,board,word,vis))
                    {
                        return true;
                    }
                }
            }
            vis[i][j]=false;//this is backtraking step
            
            return false;
            
            
           
        }
    bool exist(vector<vector < char>> &board, string word)
    {

       	//trying the bfs algo on this 
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (solve(i, j, 1, board, word,vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};