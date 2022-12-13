//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool issafe(int arr[],int mid,int n,int m)
    {
        int students=0;
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(sum+arr[i]>mid)
            {
                students++;
                sum=arr[i];
                
                if(sum>mid)return false;
            }
            else
            {
                sum+=arr[i];
            }
        }
        if(students<m)return true;
        
        return false;
    }
    int splitArray(int arr[] ,int N, int M) {
        
        
          int low=arr[0];
        int high=0;
        int ans=0;
        
        for(int i=0;i<N;i++)
        {
            low=min(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            //if i can able to fill the array then decrease my range else incerease my range
            if(issafe(arr,mid,N,M))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends