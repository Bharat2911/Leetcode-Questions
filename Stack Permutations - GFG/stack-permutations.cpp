// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        queue<int>in;
        queue<int>out;
        stack<int>st;
        
        for(int i=0;i<A.size();i++)
        {
            in.push(A[i]);
        }
        
        for(int i=0;i<B.size();i++)
        {
            out.push(B[i]);
        }
        
        while(!in.empty())
        {
            int a=in.front();
            in.pop();
            
            if(a==out.front())
            {
                out.pop();
                
                while(!st.empty())
                {
                   if(st.top()==out.front())
                   {
                       out.pop();
                       st.pop();
                   }
                   else
                   {
                       break;
                   }
                }
            }
            else
            {
                st.push(a);
            }
            
        }
        return (in.empty() and st.empty());
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends