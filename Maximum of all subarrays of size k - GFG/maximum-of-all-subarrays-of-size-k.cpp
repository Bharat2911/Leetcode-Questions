// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        // we will be using the dequeue to solve this 
        //our deque will be storing the index in decreasing order
        
        deque<int>dq;
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            //pop the ouit of bound elemnet from the front
            if(!dq.empty() and dq.front()==i-k)
            {
                dq.pop_front();
            }
            
            //pop the smaller elemnet from the end 
            while(!dq.empty() and arr[dq.back()]<=arr[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            //if window sizwe hit return the ele from front 
            //we are storing it in decreasing order because
            if(i>=k-1)
            {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends