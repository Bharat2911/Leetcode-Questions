class Solution
{
    public:
        int findPeakElement(vector<int> &nums)
        {

           	//will find this using linear searching
            int n = nums.size();
            if (n == 1)
            {
                return 0;
            }
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    if (nums[i] > nums[i + 1])
                    {
                        ans = i;
                       	break;
                    }
                }
                else if (i == n - 1)
                {
                    if (nums[i] > nums[i - 1])
                    {
                        ans = i;
                       	break;
                    }
                }
                else if (nums[i] > nums[i + 1] and nums[i] > nums[i - 1])
                {
                    ans = i;
                   	break;
                }
            }
            return ans;
        }
};