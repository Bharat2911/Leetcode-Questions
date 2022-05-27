class Solution
{
    public:
        int maxArea(vector<int> &height)
        {

           	//usign the two ppinters here 
            int n = height.size();

            int low = 0;
            int high = n - 1;

            int ans = 0;

            while (low < high)
            {
                 ans=max(ans,min(height[low],height[high])*(high-low));

                if (height[low] < height[high])
                {
                    
                     // ans=max(ans,min(height[low],height[high])*(high-low));
                    
                    low++;
                    // high--;
                }
                else
                {
                   high--;
                }
            }
            return ans;
        }
};