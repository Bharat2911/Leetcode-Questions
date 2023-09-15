//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool is_safe(int arr[],int mid,int m,int n)
    {
        int sum=0;
        int group=0;
        
        for(int i=0;i<n;i++)
        {
             if(sum+arr[i]>mid)
            {
                group++;
                sum=arr[i];
                
                if(sum>mid)return false;
            }
            else
            {
                sum+=arr[i];
            }
        }
        if(group<m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int high=0;
        int low=A[0];
        
        if(M>N)
        {
            return -1;
        }
        
        for(int i=0;i<N;i++)
        {
            low=min(low,A[i]);
            high+=A[i];
            
        }
        
        int ans=-1;
        
        //apply binary search
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(is_safe(A,mid,M,N))
            {
                ans=mid;
                
                //ans i will search for better minimum answer 
                //means i have to shrink the search space
                high=mid-1;
            }
            else
            {
                //increase my search space
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends