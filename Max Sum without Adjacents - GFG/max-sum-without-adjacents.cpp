//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	//re
	int solve(int idx,int *arr,int n,vector<int>&dp)
	{
	    //base case
	    if(idx>=n)
	    {
	        return 0;
	    }
	    if(dp[idx]!=-1)return dp[idx];
	    
	    int ans=0;
	    
	    //two casear
	    ans=max(arr[idx]+solve(idx+2,arr,n,dp),solve(idx+1,arr,n,dp));
	    
	    
	    return dp[idx]= ans;
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    //same as house robber dp
	    int idx=0;
	    
	    vector<int>dp(n+1,-1);
	    
	    
	   return solve(idx,arr,n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends