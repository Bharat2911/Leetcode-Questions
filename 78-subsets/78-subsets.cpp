class Solution
{
    public:
        void solve(int idx, vector<int> &nums, vector<vector< int >> &ans, vector< int > res)
        {
           	//base case
            if (idx == nums.size())
            {

                ans.push_back(res);
                return;
            }
            
            //choose
            res.push_back(nums[idx]);
            solve(idx+1,nums,ans,res);
            
            //not chose
            
            res.pop_back();//backtraking step;
            solve(idx+1,nums,ans,res);
            
            
        }
    vector<vector < int>> subsets(vector<int> &nums)
    {

       	//each elemnt have two options whether i will chose or will not choose
        vector<vector < int>> ans;

        vector<int> res;

        int idx = 0;

        solve(idx, nums, ans, res);

        return ans;
    }
};