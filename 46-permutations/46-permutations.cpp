class Solution {
public:
      void solve(int idx, vector<int> &nums, vector<vector< int>> &ans)
    {
       	//base case
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            
                swap(nums[idx], nums[i]);
                solve(idx + 1, nums, ans);
                swap(nums[idx], nums[i]);	//backtraking step;
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector < int>> ans;

        solve(0, nums, ans);

        return ans;
    }
};