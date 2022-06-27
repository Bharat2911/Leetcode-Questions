// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans=0;
    
   int dx[4]={-1,0,1,0};
   int dy[4]={0,1,0,-1};
    
    void solve(int i,int j,int row,int col,vector<vector<bool>>&vis,int endi,int endj,int count ,vector<vector<int>>&matrix)
    {
        //base case
        if(!matrix[endi][endj])return ;
        
        if(i==endi and j==endj)
        { 
            ans=max(ans,count);
        }
        
        vis[i][j]=true;
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and !vis[newi][newj] and matrix[newi][newj]!=0)
            {

               solve(newi,newj,row,col,vis,endi,endj,count+1,matrix);
           
            }
        }
        vis[i][j]=false;
        
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int row=matrix.size();
        int col=matrix[0].size();
        
         
        if(matrix[xs][ys]==0 || matrix[xd][yd]==0)return -1;
        
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        
        solve(xs,ys,row,col,vis,xd,yd,0,matrix);
        
        if(ans==0)return -1;
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends