class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans,vector<int>&res,int sum)
    {
        //base case
        if(idx==nums.size())
        {
            if(sum==0)
            {
                ans.push_back(res);
            }
            return;
        }
        
        //pick
        if(nums[idx]<=sum)
        {
            res.push_back(nums[idx]);
            
            solve(idx+1,nums,ans,res,sum-nums[idx]);
            
            //once recursion call is finished then i have to undo the changes
            
            res.pop_back();
        }
        
        //not pick
        //if i am not picking then i have to not pick all the occurance of current element
        while(idx+1<nums.size() and nums[idx]==nums[idx+1])idx++;
        
        solve(idx+1,nums,ans,res,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) {
        
        //concept is this if we skip then we skipp all occurance of that current element
        
        vector<vector<int>>ans;
        
        vector<int>res;
        
        int idx=0;
        
        sort(nums.begin(),nums.end());
        
        solve(idx,nums,ans,res,sum);
        
        return ans;
    }
};