//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void bfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col)
    {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        
        queue<pair<int,int>>q;
        
        q.push({i,j});
        
        vis[i][j]=1;
        
        
        while(!q.empty())
        {
            int x=q.front().first;
            
            int y=q.front().second;
            
            q.pop();
            
            for(int idx=0;idx<4;idx++)
            {
                int newi=x+dx[idx];
                
                int newj=y+dy[idx];
                
                
                if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and grid[newi][newj]==1)
                {
                    vis[newi][newj]=1;
                    
                    q.push({newi,newj});
                }
            }
        }
    }
   int numIslands(vector<vector<int>>& grid) {
        
        int row=grid.size();
        
        int col=grid[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        
        int count=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                
                if(!vis[i][j] and grid[i][j]==1)
                {
                    count++;
                    
                    bfs(i,j,grid,vis,row,col);
                }
            }
        }
        
        return count;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operations) {
        // code here
        int row=n;
        
        int col=m;
        
        vector<vector<int>>grid(row,vector<int>(col,0));
        
        vector<int>ans;
        
        for(int i=0;i<operations.size();i++)
        {
            int u=operations[i][0];
            int v=operations[i][1];
            
            grid[u][v]=1;
            
            int count=numIslands(grid);
            
            ans.push_back(count);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends