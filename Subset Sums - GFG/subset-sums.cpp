//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
   
    void solve(int idx,vector<int>&arr,int n,vector<int>&ans,int sum)
    {
        //base case
        if(idx==n)
        {
            ans.push_back(sum);
            return;
        }
        
        //pick
        solve(idx+1,arr,n,ans,sum+arr[idx]);
        
        
        //not pick
        
        solve(idx+1,arr,n,ans,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        //for each elemnt we have two options whether to take it or not take it
        
        int idx=0;
        
        int n=N;
        
        vector<int>ans;
        
        int sum=0;
        
        solve(idx,arr,n,ans,sum);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends