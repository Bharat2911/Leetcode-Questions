class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return b[1]<a[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int sz) {
        
        sort(arr.begin(),arr.end(),comp);
        
        int ans=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i][0]<=sz)
            {
                ans+=arr[i][0]*arr[i][1];
                sz-=arr[i][0];
                
            }
            else
            {
                ans+=sz*arr[i][1];
                sz-=sz;
            }
        }
        return ans;
    }
};