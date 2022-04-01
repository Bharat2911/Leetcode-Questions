class Solution {
public:
    int maxArea(vector<int>& height) {
         /*
         water store ==min(left_height,right_height)*distance betweem them
         
         */
        int ans=0;
        int low=0;
        int high=height.size()-1;
        
        while(low<=high)
        {
            ans=max(ans,min(height[low],height[high])*(high-low));
            
            if(height[low]<height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return ans;
    }
};