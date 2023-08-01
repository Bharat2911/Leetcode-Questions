//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int>A,pair<int,int>B)
    {
        if(A.second==B.second)return A.first<B.first;
        
        return B.second>A.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>ans;
        
        for(int i=0;i<n;i++)
        {
            ans.push_back({start[i],end[i]});
        }
        
        //sort on the basis of end time 
        
        sort(ans.begin(),ans.end(),comp);
        
        int i=0;
        
        int j=1;
        
        int count=1;//initially ek room to hoga hi
        
        while(j<n)
        {
            if(ans[i].second<ans[j].first)
            {
                count++;
                i=j;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends