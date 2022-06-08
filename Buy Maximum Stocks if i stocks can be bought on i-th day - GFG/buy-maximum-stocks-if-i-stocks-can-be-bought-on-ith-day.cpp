// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        //greedy we puck the less amount stock firsts to get the maximum stocks
       vector<pair<int,int>> v;
       for(int i = 0; i < n; i++)
       {
           v.push_back({price[i],i+1});
       }
       sort(v.begin(),v.end());
       int ans = 0;
       int amt = 0;
       for(int i = 0; i < n; i++)
       {
           if(amt < k and v[i].first*v[i].second <= k - amt)
           {
           // case 1 can buy complete stocks
               amt += v[i].first*v[i].second;
               ans += v[i].second;
           }
           else if(amt < k and v[i].first*v[i].second > k - amt)
           {
           // case 2 can buy some stocks
               int stocks = (k - amt)/v[i].first;
               amt += stocks*v[i].first;
               ans += stocks;
           }
           else{
           // cant buy
               break;
           }
       }
       return ans;
   
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends