class Solution {
public:
    void solve(vector<int>&nums,int idx,int sum,vector<vector<int>>&res,vector<int>&ans)
    {
        //base case
        if(idx==nums.size())
        {
            if(sum==0)
            {
                res.push_back(ans);
            }
            return;
        }
        
        //pick 
        if(nums[idx]<=sum)
        {
            ans.push_back(nums[idx]);
            
            solve(nums,idx,sum-nums[idx],res,ans);
            
            ans.pop_back();//backtraking step
        }
        
        //not pick
        
        solve(nums,idx+1,sum,res,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int sum) {
     
        //this is a backtraking bitch jii
     
        vector<vector<int>>res;
        vector<int>ans;
        
        int idx=0;
        
        solve(nums,idx,sum,res,ans);
        
        return res;
    }
};