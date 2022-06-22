// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
vector<vector<int>> ans;
   vector<int>curr;
   void solve(vector<vector<int>> &grid,int row,int col)
   {
       int n=grid.size(),m=grid[0].size();
       if(row>=n||col>=m)return ;
       if(row==n-1&&col==m-1)
       {
           curr.push_back(grid[row][col]);
           ans.push_back(curr);
           curr.pop_back();
           return ;
       }
       curr.push_back(grid[row][col]);
       solve(grid,row+1,col);
       solve(grid,row,col+1);
       curr.pop_back();
   }
   vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
   {
       solve(grid,0,0);
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends