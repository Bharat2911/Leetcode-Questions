class Solution
{
    public:
        void solve(int idx, vector<int> &nums, vector<vector< int >> &ans, vector< int > &res)
    {
        if (idx == nums.size())
        {
            ans.push_back(res);
            return;
        }
        
        res.push_back(nums[idx]);
        solve(idx+1,nums,ans,res);
        res.pop_back();
        
        solve(idx+1,nums,ans,res);
    }
    vector<vector < int>> subsets(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector < int>> ans;

        vector<int> res;

        solve(0, nums, ans, res);

        return ans;
    }
};