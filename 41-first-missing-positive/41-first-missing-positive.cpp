class Solution
{
    public:
        void remove(vector<int> &nums)
        {
           	//nums is sorted actually

            int n = nums.size();
            // sort(nums.begin(), nums.end());

            int current = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                if (current == nums[i])
                {
                    nums.erase(nums.begin() + i);
                    i--;
                }
                current = nums[i];
            }
        }
    int firstMissingPositive(vector<int> &nums)
    {
       	//if we have the duplicates then we have to remove those duplicates

        int count = 1;

        sort(nums.begin(), nums.end());

        remove(nums);

        for (auto itr: nums)
        {
            if (itr < 1) continue;

            else if (itr != count)
            {
                return count;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};