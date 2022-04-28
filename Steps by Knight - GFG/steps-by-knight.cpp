// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int n)
	{
	    // Code here
	    //simply bfs question
	    //will us the visited vector as answer also to store the answer in it
	    queue<pair<int,int>>q;
	    //kinght can move in 8 directions
	    int dx[]={1,2,1,2,-1,-2,-1,-2};
        int dy[]={-2,-1,2,1,-2,-1,2,1};
	    
	    vector<vector<int>>vis(n,vector<int>(n,-1));
	    
	    q.push({kp[0]-1,kp[1]-1});//push the starting position int the queue convert in 0 basing 
	    vis[kp[0]-1][kp[1]-1]=0;//since i am using the vis to sttore the ans
	    
	    while(!q.empty())
	    {
	        int i=q.front().first;
	        int j=q.front().second;
	        
	        q.pop();
	        
	        for(int idx=0;idx<8;idx++)
	        {
	            int newi=i+dx[idx];
	            int newj=j+dy[idx];
	            
	            //base case
	            if(newi>=0 and newi<n and newj>=0 and newj<n and vis[newi][newj]==-1  )
	            {
	                vis[newi][newj]=1+vis[i][j];
	                
	                q.push({newi,newj});
	            }
	        }
	        
	    }
	    return vis[tp[0]-1][tp[1]-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends