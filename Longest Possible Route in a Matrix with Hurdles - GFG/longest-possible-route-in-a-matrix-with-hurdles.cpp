// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
//bfs always give the shortest path so we wil be usnt 
    vector<int> rh, ch ;
 
int dfs(vector<vector<int>>& m, int xs, int ys, int& xd, int& yd,int &r, int& c,vector< vector<bool>>& vis){
    if(!m[xs][ys])
        return -1 ;
    
    if(xs == xd && ys == yd)
        return 0 ;
    
    vis[xs][ys] = true ;
    int ans = -1 ;
    for(int i=0; i<4 ; i++){
        int nx = xs + rh[i] , ny = ys + ch[i] ;
        if(nx >= 0 && ny >= 0 && nx < r && ny < c && !vis[nx][ny]){
            int tans = dfs(m,nx,ny,xd,yd,r,c,vis) ;
            if(tans != -1)
                ans = max(ans,1+tans) ;
        }
    }
    vis[xs][ys] = false ;
    return ans ;
}

int longestPath(vector<vector<int>>& m, int xs, int ys, int xd, int yd)
{   
    rh = {-1,0,0,1} , ch = {0,-1,1,0} ; 
    int r = m.size(), c = m[0].size() ;
    vector< vector<bool>> vis(r, vector<bool>(c,false)) ;
    return dfs(m,xs,ys,xd,yd,r,c,vis) ;
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