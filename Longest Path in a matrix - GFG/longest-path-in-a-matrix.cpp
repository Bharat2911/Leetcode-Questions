// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& vis)
    {
         int row=matrix.size();
        int col=matrix[0].size();
        
        if(vis[i][j]!=-1)return vis[i][j];
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        int count=1;
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            
            if(newi>=0 and newi<row and newj>=0 and newj<col  and matrix[newi][newj]>matrix[i][j])
            {
                
                
                count=max(count,1+solve(newi,newj,matrix,vis));
            }
        }
        return  vis[i][j]=count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
          int row=matrix.size();
        int col=matrix[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,-1));
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               
                   ans=max(ans,solve(i,j,matrix,vis));
                
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends