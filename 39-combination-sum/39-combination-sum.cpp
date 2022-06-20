class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans,int sum)
    {
        //base case
        
        if(index==nums.size())
        {
            if(sum==0)
            {
                ans.push_back(res);
            }
            return;
        }
        
        //pick 
        if(nums[index]<=sum)
        {
            res.push_back(nums[index]);
            
            solve(index,nums,res,ans,sum-nums[index]);
            
            res.pop_back();//backtraking step
            
        }
        
        //not pick 
        solve(index+1,nums,res,ans,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int sum) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        int index=0;
        solve(index,nums,res,ans,sum);
        
        return ans;
        
    }
};