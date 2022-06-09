// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        // Your code here
          stack<long long >s;
        long long i=0;
        long long ma=0;
        
        while(i<n)
        {
            if( s.empty() or arr[s.top()]<=arr[i])
            {
                s.push(i++);
            }
            else{ 
                long long ele=s.top();
                s.pop();
                long long ans=arr[ele]*(s.empty()?i:i-s.top()-1);
                ma=max(ma,ans);
            
            }
        }
        while(!s.empty())
        {
            long long ele=s.top();
            s.pop();
            long long ans=arr[ele]*(s.empty()?i:i-s.top()-1);
            ma=max(ma,ans);
        }
        return ma;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends