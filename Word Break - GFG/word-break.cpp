// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
int solve(int index,string &A ,vector<string>&B)
{
    //base case
    if(index==A.length())
    {
        return 1;
    }
    
    for(auto itr:B)
    {
        int l=itr.length();
        
        // a ki same length ke substr
        string str=A.substr(index,l);
        
        if(str==itr)
        {
            if(solve(index+l,A,B))return true;
        }
    }
    return false;
}
    int wordBreak(string A, vector<string> &B) {
        //code here
        int index=0;
        
       return solve(index,A,B);
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends