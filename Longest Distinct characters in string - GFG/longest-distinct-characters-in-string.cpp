//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    unordered_map<char,int>map;
    
    int n=S.length();
    
    int i=0;
    int j=0;
    
    int ans=0;
    
    while(j<n)
    {
        map[S[j]]++;
        
        if(map.size()==j-i+1)
        {
            ans=max(ans,j-i+1);
        }
        else
        {
            while(map.size()<j-i+1)
            {
                map[S[i]]--;
                
                if(map[S[i]]==0)
                {
                    map.erase(S[i]);
                }
                i++;
            }
        }
        j++;
        
    }
    return ans;
}