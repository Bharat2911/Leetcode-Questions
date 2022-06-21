class Solution
{
    public:
       	//simple logic ->use the concept of permutaion and before making the permutaion check the conditions

        void solve(int index, vector<int> &nums, vector<vector< int>> &ans)
        {
            if (index == nums.size())
            {
                ans.push_back(nums);
                return;
            }

            for (int i = index; i < nums.size(); i++)
            {
                int condition_1 = nums[i] % (index + 1);
                int condition_2 = (index + 1) % nums[i];

                if (condition_1 == 0 || condition_2 == 0)
                {
                    swap(nums[index], nums[i]);

                    solve(index + 1, nums, ans);

                    swap(nums[index], nums[i]);
                }
            }
        }
    int countArrangement(int n)
    {

        vector<int> nums;

        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        vector<vector<int>>ans;
        
        solve(0,nums,ans);
        
        return ans.size();
        
    }
};