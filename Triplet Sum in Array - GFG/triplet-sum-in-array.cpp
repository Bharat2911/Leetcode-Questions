//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        
        sort(A,A+n);
        
        int count=0;
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                if(A[i]+A[j]+A[k]==X)
                {
                    count++;
                    j++;
                    k--;
                }
                else if(A[i]+A[j]+A[k]>X)
                {
                    k--;
                
                }
                else
                {
                    j++;
                }
            }
        }
        return count;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends