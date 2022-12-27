//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int n)
{
    // Your code goes here
    //just use two pointers
    
    //T.C=O(n)
    //S.C=O(1)
    
  
        
        int low=0;
        int high=n-1;
        
        long long ans=0;
        
        while(low<high)
        {
            long long len=high-low;
            
            long long area=min(arr[low],arr[high])*len;
            
            
            ans=max(ans,area);
            
            
            if(arr[low]<arr[high])
            {
                low++;
            }
            else 
            {
                high--;
            }
        }
        return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends