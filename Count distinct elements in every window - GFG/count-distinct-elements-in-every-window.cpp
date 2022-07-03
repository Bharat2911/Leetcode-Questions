// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        //we will be applying the sliding window in this na bro
        vector<int>ans;
        
        unordered_map<int,int>map;
        int i=0;
        int j=0;
        
        while(j<n)
        {
            //calculations
            
            map[A[j]]++;
            
            if(j-i+1<k)
            {
                j++;
                
            }
            
            else if(j-i+1==k)
            {
                //calculater the answer
                int count=map.size();
                ans.push_back(count);
                
                map[A[i]]--;
                if(map[A[i]]==0)
                {
                    map.erase(A[i]);
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends