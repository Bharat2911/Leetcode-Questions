//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,int row,int col,vector<vector<int>>&grid,int dx[],int dy[],int n)
    {
        int ans=0;
        
        for(int idx=0;idx<n;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            if(newi>=0 and newi<row and newj>=0 and newj<col )
            {
                // cout<<grid[newi][newj]<<" ";
                ans+=grid[newi][newj];
            }
        }
        return ans;
    }
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        // for 1 step
        int row=n;
        int col=m;
        int dx1o[] = {-1,0,1,1,1,0};

        int dy1o[] = {0,1,1,0,-1,-1};

        int dx1e[] = {-1,-1,0,1,0,-1};

        int dy1e[] = {0,1,1,0,-1,-1};

        //for 2step

        int dx2o[] = {-1,-1,-2,-1,-1,0,0,1,1,2,2,2};

        int dy2o[] = {-2,-1,0,1,2,-2,2,-2,2,-1,0,1};

         int dx2e[] = {-2,-2,-2,-1,-1,0,0,1,1,1,1,2};

        int dy2e[] = {-1,0,1,-2,2,-2,2,-2,-1,1,2,0};

        // 1step

        int ans = 0;

        if(ty == 0)

        {

            if(j%2 == 0)

            {

                ans = solve(i,j,row,col,mat,dx1e,dy1e,6);

            }

            else

            {

                ans = solve(i,j,row,col,mat,dx1o,dy1o,6);

            }

        }

        else

        {

            //2step

            if(j%2 == 0)

            {

                ans = solve(i,j,row,col,mat,dx2e,dy2e,12);

            }

            else

            {

                ans = solve(i,j,row,col,mat,dx2o,dy2o,12);

            }

        }

        

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends