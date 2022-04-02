class Solution
{
    public:
        int rec(vector<int> &nums, int n, int dp[], int x)
        {
            if (n <= 1 - x) return 0;
            if (dp[n] != -1) return dp[n];
            return dp[n] = max(nums[n - 1] + rec(nums, n - 2, dp, x), rec(nums, n - 1, dp, x));
        }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
       	//from N to 1
        int op1 = rec(nums, n, dp, 0);

        memset(dp, -1, sizeof(dp));
       	//from N-1 to 0
        int op2 = rec(nums, n - 1, dp, 1);

       	//max of both the parts
        return max(op1, op2);
    }
    };