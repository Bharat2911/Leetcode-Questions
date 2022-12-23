class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n = nums.size();
            
            if(n==1)return 0;
            
            vector<int> left(n);
            vector<int> right(n);

            left[0] = nums[0];
            right[n - 1] = nums[n - 1];

            for (int i = 1; i < n; i++)
            {
                left[i] = left[i - 1] + nums[i];
            }
            for (int j = n - 2; j >= 0; j--)
            {
                right[j] = right[j + 1] + nums[j];
            }

            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    if (right[i + 1] == 0)
                    {
                        return i;
                    }
                }
                else if (i == n - 1)
                {
                    if (left[i - 1] == 0)
                    {
                        return i;
                    }
                }
                else if (left[i - 1] == right[i + 1])
                {
                    return i;
                }
            }
            return -1;
    }
};