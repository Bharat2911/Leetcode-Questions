//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
         int max_ele=max(a[0],a[1]);
         
         int second_max=min(a[0],a[1]);
         
         int third_max=INT_MIN;
         
         for(int i=2;i<n;i++)
         {
             if(a[i]>third_max)
             {
                 third_max=a[i];
             }
             if(a[i]>second_max)
             {
                 third_max=second_max;
                 second_max=a[i];
             }
             if(a[i]>max_ele)
             {
                 second_max=max_ele;
                 
                 max_ele=a[i];
             }
             
         }
         
         return third_max;
    }

};

//{ Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends