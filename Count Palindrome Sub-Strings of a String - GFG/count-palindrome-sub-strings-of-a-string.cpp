// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char S[], int N)
{
    //code here
    vector<vector<bool>> dp (N+1,vector<bool> (N+1,false));
dp[0][0]=true;
dp[N][N] =true;
int cnt=0;
for(int i =N-1;i>=1;i--){
for(int j =i;j<=N;j++){
if(i==j || ((j==i+1 || dp[i+1][j-1]) && S[i-1]==S[j-1])) {
dp[i][j]=true;
if(j-i+1 >=2) cnt++;
}
}
}
return cnt;
    
}