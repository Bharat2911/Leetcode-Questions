class Solution {
public:
    void solve(int idx,vector<int>&arr,vector<vector<int>>&ans,vector<int>&res,int sum)
    {
        if(sum==0)
        {
            ans.push_back(res);
        }
        if(sum<0)
        {
            return;
        }
        for(int i=idx;i<arr.size();i++)
        {
            if( i>0 and i>idx and arr[i]==arr[i-1])continue;
            
            res.push_back(arr[i]);
            solve(i+1,arr,ans,res,sum-arr[i]);
            
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int sum) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int idx=0;
        
        solve(idx,arr,ans,res,sum);
        
        return ans;
    }
};