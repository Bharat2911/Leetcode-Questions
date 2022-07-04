// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        //will maintain a min heap here
        vector<int>ans;
        
        // T.C ==O(n log k)
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<num;i++)
        {
            //push in pq and as soon its size greater than k pop from it ans push top in ans
            pq.push(arr[i]);
            
            if(pq.size()>k)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        //push all the remaining ele in the ans
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends