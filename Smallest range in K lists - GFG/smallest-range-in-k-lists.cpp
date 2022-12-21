//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int nums[][N], int n, int k)
    {
          //code here
           
        
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<k;i++)
        {
            int first_ele=nums[i][0];
            
            maxi=max(maxi,first_ele);
            mini=min(mini,first_ele);
            
            pq.push({first_ele,{i,0}});
        }
        int low=mini;
        int high=maxi;
        
        while(!pq.empty())
        {
            int mini=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(maxi-mini<high-low)
            {
                low=mini;
                high=maxi;
            }
            if(col+1<n)
            {
                maxi=max(maxi,nums[row][col+1]);
                pq.push({nums[row][col+1],{row,col+1}});
            }
            else
            {
                break;
            }
        }
        return {low,high};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends