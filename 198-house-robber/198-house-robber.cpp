class Solution
{
    public:
        int solve(int idx, vector<int> &nums,vector<int>&dp)
        {
           	//base case
            if(idx==0)return nums[idx];
            if (idx < 0) return 0;
            if(dp[idx]!=-1)return dp[idx];
            
           	//choice diagram 

            int pick = nums[idx] + solve(idx - 2, nums,dp);	//agar le rha hu to adjacent elel nahi lung
            int not_pick = solve(idx - 1, nums,dp);

            return dp[idx]=max(pick, not_pick);
        }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        
        return solve(n - 1, nums,dp);
    }
};