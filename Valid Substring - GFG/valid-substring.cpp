// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int ans=0;
        int n=s.length();
        
        int open=0;
        int close=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open==close)
            {
                ans=max(ans,2*open);
            }
            else if(close>open)
            {
                open=0;
                close=0;
                
            }
        }
        open=0;
        close=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else
            {
                close++;
            }
            
            if(open==close)
            {
                ans=max(ans,2*open);
            }
            else if(open>close)
            {
                open=0;
                close=0;
                
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends