class Solution
{
    public:
        int binary_search(vector<int> &nums, int low, int high, int target)
        {
            while (low <= high)
            {
                int mid = (low + high) / 2;

                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return -1;
        }
    int search(vector<int> &nums, int target)
    {

       	//step 1->find the index of min element
        int mini = nums[0];
        int idx = 0;
        int n=nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < mini)
            {
                mini = nums[i];
                idx = i;
            }
        }

        int left = binary_search(nums, 0, idx - 1, target);
        int right = binary_search(nums, idx, n - 1, target);

        if (left == -1)
        {
            return right;
        }
        else if (right == -1)
        {
            return left;
        }
        else

        {
            return -1;
        }
    }
};