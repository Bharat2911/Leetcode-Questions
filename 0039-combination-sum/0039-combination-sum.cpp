class Solution {
public:
    void solve(vector<int>&nums,int sum,int idx,vector<vector<int>>&ans,vector<int>&res)
    {
        if(idx==nums.size())
        {
            if(sum==0)
            {
                ans.push_back(res);
            }
            return ;
        }

        //two choices
        
        if(nums[idx]<=sum)
        {
            res.push_back(nums[idx]);
            
            solve(nums,sum-nums[idx],idx,ans,res);
            
            //backtraking step
            res.pop_back();
        }
        
        
            solve(nums,sum,idx+1,ans,res);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        
        int idx=0;
        
        int sum=target;
        
        vector<int>res;
        
        solve(nums,sum,idx,ans,res);
        
        return ans;
        
    }
};