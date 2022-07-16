class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {

           	//basically wee have three approach to solve this

           	//Approach 1-> brute force

           	//time complexity-O(n^2)

           	//Approach 2->time optimised

           	//time complexity->O(n)
           	// space complexity ->o(n);

           	//Approach 3-> time and space optimised

           	//time complexity ->O(n);
           	//space complexity-O(1);

           	// Approach ->2
           	//concept current answer will be preoduct of all the elemne ton its left to the all the elemnets on its right

            int n = nums.size();

            vector<int> left(n);
            vector<int> right(n);
            left[0] = nums[0];
            right[n - 1] = nums[n - 1];

            vector<int> ans(n);

           	//liff left and right with suffic product
            for (int i = 1; i < n; i++)
            {
                left[i] = left[i - 1] *nums[i];
            }
            for(int i=n-2;i>=0;i--)
            {
                right[i]=right[i+1]*nums[i];
                
            }
            ans[0]=right[1];
            ans[n-1]=left[n-2];
            
            for(int i=1;i<n-1;i++)
            {
                ans[i]=left[i-1]*right[i+1];
            }
            return ans;
        }
};