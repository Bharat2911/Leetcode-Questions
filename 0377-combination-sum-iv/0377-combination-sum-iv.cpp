class Solution {
public:
    int solve(vector<int>&nums, int target, vector<int> &dp){
        if(target == 0) return 1;
        if(target<0) return INT_MIN;

        if(dp[target] != -1) return dp[target];
        
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
        
        int p = solve(nums, target-nums[i], dp);
        if(p != INT_MIN)
              ans += p;
        }

        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};