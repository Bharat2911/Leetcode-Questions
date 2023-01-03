//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int nums[], int n) {
        // code here
        
        //approach find the length of the maximum 
        //T.C=O(n^2)
        //S.C=O(1);
        
        
        // vector<int>dp(n,1);//min length sab elemnts ki 1 hogi hi
        
        
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<i;j++)
        //     {
        //         if(nums[i]>nums[j] and dp[i]<dp[j]+1)
        //         {
        //           dp[i]=dp[j]+1;
        //         }
        //     }
        // }
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     ans=max(ans,dp[i]);
        // }
        // return n-ans;
        
        //if we use the binary search approach then 
        //T.C=O(n)
        //S.C=O(n)
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                
                ans[idx]=nums[i];
            }
        }
        return n-ans.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends