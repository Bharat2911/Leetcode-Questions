class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int extra) {
        
        int n=arr.size();
        
        int curr_max=0;
        
        vector<bool>ans(n);
        
        for(auto itr:arr)
        {
            curr_max=max(curr_max,itr);
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]+extra>=curr_max)
            {
                ans[i]=true;
                // curr_max=arr[i]+extra;
            }
            else
            {
                ans[i]=false;
            }
        }
        return ans;
    }
};