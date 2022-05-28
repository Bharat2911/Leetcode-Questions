// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
           bool Dp[N + 1] = {0};
       Dp[0] = 1;     
       sort(begin(A), end(A));
       for (int i = K; i <= N; ++i) {
           int j = lower_bound(begin(A), end(A), A[i - 1] -  M) - begin(A);
           for (int n = j; n <= i - K; ++n) {
               Dp[i] = Dp[i] || Dp[n];
           if (Dp[i]) {
               break;
           }    
           }
       }
       return Dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends