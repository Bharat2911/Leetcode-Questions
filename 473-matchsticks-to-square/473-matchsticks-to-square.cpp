class Solution
{
    public:
        bool solve(vector<int> &nums, vector<int> &vis, int index, int k, int curr_sum, int &sum)
        {
            if (k == 0) return true;

            if (curr_sum > sum) return false;

            if (curr_sum == sum)
            {
                return solve(nums, vis, 0, k - 1, 0, sum);
            }

            for (int i = index; i < nums.size(); i++)
            {
                if (vis[i]) continue;

                vis[i] = 1;

                if (solve(nums, vis, i + 1, k, curr_sum + nums[i], sum)) return true;

                vis[i] = 0;

                if (curr_sum == 0) break;
            }

            return false;
        }
    bool makesquare(vector<int> &nums)
    {

        
            int k = 4;

            int total_sum = 0;
            int curr_sum = 0;

            int index = 0;
            int mx = 0;

            for (auto itr: nums)
            {
                total_sum += itr;
            }

            if (total_sum % k != 0) return false;

            if (nums.size() < k) return false;

            total_sum = total_sum / k;

            vector<int> vis(nums.size(), 0);

            return solve(nums, vis, index, k, curr_sum, total_sum);
        }
       	//     bool makesquare(vector<int>& matchsticks) {

       	// }
    };