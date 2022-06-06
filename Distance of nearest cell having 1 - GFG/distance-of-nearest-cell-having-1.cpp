// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    //apan zero se one nahi jaate hue one se zero jaayenge
	    int row=grid.size();
	    int col=grid[0].size();
	    
	    queue<pair<int,int>>q;
	    
	    vector<vector<int>>ans(row,vector<int>(col,INT_MAX));//int max se sabko fill kar diya beti
	    
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                ans[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int i=q.front().first;
	        int j=q.front().second;
	        q.pop();
	        
	        //now the four conditions
	        
	        if(i-1>=0 and ans[i][j]+1<ans[i-1][j])
	        {
	            ans[i-1][j]=ans[i][j]+1;
	            q.push({i-1,j});
	        }
	        
	        if(j-1>=0 and ans[i][j]+1<ans[i][j-1])
	        {
	            ans[i][j-1]=1+ans[i][j];
	            
	            q.push({i,j-1});
	        }
	        
	        if(i+1<row and ans[i][j]+1<ans[i+1][j])
	        {
	            ans[i+1][j]=ans[i][j]+1;
	            q.push({i+1,j});
	        }
	        if(j+1<col and ans[i][j]+1<ans[i][j+1])
	        {
	            ans[i][j+1]=ans[i][j]+1;
	            q.push({i,j+1});
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends