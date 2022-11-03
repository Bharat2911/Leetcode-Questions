//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
        int dx[8]={0,1,1,1,0,-1,-1,-1};
        
        int dy[8]={1,1,0,-1,-1,-1,0,1};
        
        vis[i][j]=true;
        
        
        for(int idx=0;idx<8;idx++)
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
    bool exist(vector<vector<char>>& board, string &word) {
        
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
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& words) {
	    // Code here
	    
	      vector<string>ans;
        
        for(auto itr:words)
        {
            if(exist(board,itr))
            {
                ans.push_back(itr);
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends