class Solution {
public:
    void solve(vector<int>&arr,int target,int sum,int idx,vector<vector<int>>&ans,vector<int>&res)
    {
        //bae csae
        
        if(idx==arr.size())
        {
            if(target==0)
            {
                ans.push_back(res);
            }
            return;
        }
        //once we include the elemnt 
        //we wil only add if current element is less than equal to target
        if(arr[idx]<=target)
        {
            res.push_back(arr[idx]);
            solve(arr,target-arr[idx],sum,idx,ans,res);
            res.pop_back();//backtaking step
            
        }
        
        //if we dont choose
        solve(arr,target,sum,idx+1,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        //wach elel has two options wether to pick or not pick
        int sum=0;
        int idx=0;
        
        vector<vector<int>>ans;
        vector<int>res;
        
        solve(candidates, target, sum, idx,ans,res);
        
        return ans;

    }
};