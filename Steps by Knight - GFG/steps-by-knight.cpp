// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
		bool isvalid(int i,int j,int n,vector<vector<bool>>&vis)
    {
        if(i>=0 and i<n and j>=0 and j<n and !vis[i][j])
        {
            return true;
        }
        return false;
        
    }
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int n)
	{
	    // Code here
	    int s1=kp[0]-1;
	    int s2=kp[1]-1;
	    
	    int ti=tp[0]-1;
	    int tj=tp[1]-1;
	    
	    if(s1==ti and s2==tj)
	    {
	        return 0;
	    }
	    queue<pair<int,int>>q;
	    vector<vector<bool>>vis(n,vector<bool>(n,false));
	    
	    q.push({s1,s2});
	    vis[s1][s2]=true;
	    int ans=0;
	    
	    while(!q.empty())
	    {
	        ans++;
	        int sz=q.size();
	        
	        while(sz--)
	        {
	            int i=q.front().first;
	            int j=q.front().second;
	            q.pop();
	            
	            int dx[]={1,2,1,2,-1,-2,-1,-2};
                int dy[]={-2,-1,2,1,-2,-1,2,1};
                
                for(int idx=0;idx<8;idx++)
                {
                    int newi=i+dx[idx];
                    int newj=j+dy[idx];
                    
                    //means i have reached the target pos
                    if(newi==ti and newj==tj)
                    {
                        return ans;
                    }
                    
                    if(isvalid(newi,newj,n,vis))
                    {
                        vis[newi][newj]=true;
                        q.push({newi,newj});
                    }
                }
	            
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