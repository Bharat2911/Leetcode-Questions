// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        //make the frequency array
        int n=s.length();
        vector<int>freq(26,0);
        
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        priority_queue<int>pq;
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                pq.push(freq[i]);
            }
        }
        
        while(!pq.empty() and k>0)
        {
            int top=pq.top();
            pq.pop();
            
            top=top-1;
            k--;
            
            pq.push(top);
        }
        int sum=0;
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            
            sum+=top*top;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends