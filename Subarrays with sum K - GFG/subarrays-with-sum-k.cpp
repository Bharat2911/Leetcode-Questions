//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int K)
    {
        // code here
        unordered_map<int,int>map;
        
        map[0]=1;
        
        int sum=0;
        int count=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=Arr[i];
            
            if(map.find(sum-K)!=map.end())
            {
                count+=map[sum-K];
            }
            map[sum]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends