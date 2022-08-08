class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int i=0;
        int j=n-1;
        
        int left_max=0;
        int right_max=0;
        
        int area=0;
        
        while(i<j)
        {
            left_max=max(left_max,height[i]);
            
            right_max=max(right_max,height[j]);
            
            
            if(left_max>right_max)
            {
                area+=right_max-height[j];
                j--;
            }
            else
            {
                area+=left_max-height[i];
                i++;
            }
        }
        return area;
    }
};