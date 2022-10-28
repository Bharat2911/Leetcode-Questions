class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //pani store to minimum height ke beech me hi hoga na bro
        int n=height.size();
        
        int low=0;
        
        int high=n-1;
        
        int ans=0;
        
        while(low<high)
        {
            int possible_water=min(height[low],height[high]);
            
            int area=possible_water*(high-low);
            
            ans=max(ans,area);
            
            
            //increament the pointersa
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