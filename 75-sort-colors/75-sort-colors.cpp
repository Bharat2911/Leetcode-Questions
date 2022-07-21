class Solution
{
    public:
       	//pointer approach 

        void sortColors(vector<int> &nums)
        {

           	//two approaches
           	//1-> o(n),O(n)
           	//2->O(n).O(1)

            int n = nums.size();

            int low = 0;
            int mid = 0;
            int high = n - 1;

            while (mid <= high)
            {
                switch (nums[mid])
                {
                    case 0:
                        swap(nums[low++], nums[mid++]);
                        break;
                    case 1:
                        mid++;
                        break;

                    case 2:
                        swap(nums[mid], nums[high--]);
                        break;
                }
            }
        }
};