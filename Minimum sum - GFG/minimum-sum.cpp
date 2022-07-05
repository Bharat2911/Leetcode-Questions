// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        
        
        sort(arr,arr+n);
        string a="",b="";
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                continue;
            }
            if(i%2==0){
                a+=to_string(arr[i]);
            }else{
                b+=to_string(arr[i]);
            }
        }
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int sum=0,rem=0;
        while(i>=0 || j>=0){
            sum=0;
            if(i>=0){
                sum+=(a[i--]-'0');
            }
            if(j>=0){
                sum+=(b[j--]-'0');
            }
            sum+=rem;
            ans+=to_string(sum%10);
            rem=sum/10;
        }
        if(rem>0){
            ans+=to_string(rem);
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends