class Solution {
public:
    void solve(int idx,vector<int>&arr,vector<vector<int>>&ans,vector<int>&res,int sum)
    {
        if(idx==arr.size())
        {
            if(sum==0)
            {
                ans.push_back(res);
            }
            return;
        }
        
        //pick 
        
        if(arr[idx]<=sum)
        {
            res.push_back(arr[idx]);
            solve(idx,arr,ans,res,sum-arr[idx]);
            res.pop_back();//back_traking step
        }
        //not pick
        solve(idx+1,arr,ans,res,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int sum) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        int idx=0;
        
        solve(idx,arr,ans,res,sum);
        
        return ans;
    }
};