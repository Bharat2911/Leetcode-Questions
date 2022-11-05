class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        
        int i=0;
        
        int j=n-1;
        
        int ans=INT_MIN;
        
        while(i<j)
        {
            int level=min(height[i],height[j]);
            
            int len=j-i;
            
            ans=max(ans,len*level);
            
            
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
           
        }
        return ans;
    }
};