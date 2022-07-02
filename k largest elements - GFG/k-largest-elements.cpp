// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    //brute force 
	    //sort and return the arr[k-1]
	    //T.C = o(nlog n)
	    
	    
	    //we can optimised it to O(n log k)
	    
	    //rather than itrate all the ele we will just itrate the k ele 
	    priority_queue<int>pq;
	    vector<int>ans;
	    for(int i=0;i<n;i++)
	    {
	        pq.push(arr[i]);
	    }
	    while(!pq.empty() and k>0)
	    {
	        int t=pq.top();
	        pq.pop();
	        
	        ans.push_back(t);
	        k--;
	    }
	    
	    return ans;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends