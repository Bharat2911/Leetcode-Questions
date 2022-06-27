// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
   bool solve(int index, int curr_sum, int &sum, int nums[], vector<int> &vis, int k,int n)
        {
           	//base case
            if (k == 0) return true;

            if (curr_sum > sum) return false;

            if (curr_sum == sum)
            {
                return solve(0, 0, sum, nums, vis, k - 1,n);
            }

            for (int i = index; i < n; i++)
            {
                if (!vis[i])
                {
                    vis[i] = 1;

                    if (solve(i + 1, curr_sum + nums[i], sum, nums, vis, k,n)) return true;

                    vis[i] = 0;
                    if(curr_sum==0)break;
                }
            }
            return false;
        }
    bool isKPartitionPossible(int nums[], int n, int k)
    {
         //Your code here
         int total_sum = 0;
        int curr_sum = 0;

        int index = 0;
        int mx = 0;

        for (int i=0;i<n;i++)
        {
            total_sum += nums[i];
        }

        if (total_sum % k != 0) return false;

        if (n < k) return false;

        vector<int> vis(n, 0);
        total_sum=total_sum/k;
        return solve(index, curr_sum, total_sum, nums, vis, k,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends