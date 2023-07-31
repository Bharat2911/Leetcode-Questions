//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int n=N;
      
      set<int>set;
      
      int ans=0;
      
      
      for(int i=0;i<n;i++)
      {
          set.insert(arr[i]);
      }
      
      for(int i=0;i<n;i++)
      {
          if(!set.count(arr[i]-1))
          {
              int curr=arr[i];
              int count=1;
              
              while(set.count(curr+1))
              {
                  count++;
                  curr+=1;
                  
              }
              ans=max(ans,count);
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends