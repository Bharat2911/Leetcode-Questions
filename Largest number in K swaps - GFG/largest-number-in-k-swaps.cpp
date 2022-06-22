// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int index,string&str,int n,int k,string&ans)
    {
        //basse case
        if(k==0)
        {
            return;
        }
        
        char max_char=str[index];
        
        for(int i=index+1;i<n;i++)
        {
            if(str[i]>max_char)
            {
                max_char=str[i];
            }
        }
        //we have complete our one swap so decrement the k
        if(max_char!=str[index])
        {
            k--;
        }
        
        //we have to swap now
        for(int i=n-1;i>=0;i--)
        {
            if(str[i]==max_char)
            {
                swap(str[i],str[index]);
                
                if(ans<str)
                {
                    ans=str;
                }
                //send the recursive call fro the rest of the strgin
                solve(index+1,str,n,k,ans);
                //backtraking step
                
                swap(str[i],str[index]);
                
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       int n=str.length();
       
        string ans="";
        int index=0;
        
        solve(index,str,n,k,ans);
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends