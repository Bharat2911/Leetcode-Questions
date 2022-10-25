class Solution
{
    public:
        void solve(int idx, vector<int> &arr, vector<vector< int >> &ans, vector< int > &res, int target)
        {
            if (target == 0)
            {
                ans.push_back(res);
                return;
            }
            for (int i = idx; i < arr.size(); i++)
            {
                if (i > idx and arr[i] == arr[i - 1]) continue;

               	// if (arr[i]>target)break;
                if (arr[i] <= target)
                {
                    res.push_back(arr[i]);
                    solve(i + 1, arr, ans, res, target - arr[i]);
                    res.pop_back();
                }
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &arr, int target)
    {

        sort(arr.begin(), arr.end());

        vector<vector < int>> ans;

        vector<int> res;

        solve(0, arr, ans, res, target);

        return ans;
    }
};