class Solution
{
    public:
        void solve(int index, vector<int> &nums, vector<vector< int >> &res, vector< int > &ans)
        {
            res.push_back(ans);

            for (int i = index; i < nums.size(); i++)
            {
                if(i!=index and nums[i]==nums[i-1])continue;
                
                ans.push_back(nums[i]);

                solve(i + 1, nums, res, ans);

                ans.pop_back();
            }
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector < int>> res;
        vector<int> ans;
        sort(nums.begin(), nums.end());

        solve(0, nums, res, ans);

        return res;
    }
};