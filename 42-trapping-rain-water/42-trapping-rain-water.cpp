class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int left=0;
        int right=0;
        
        int i=0;
        int j=n-1;
        
        int ans=0;
        
        
        while(i<j)
        {
            left=max(left,height[i]);
            
            right=max(right,height[j]);
            
            
            if(left>right)
            {
                ans+=right-height[j];
                j--;
                cout<<ans<<" ";
            }
              // cout<<endl;
            else 
            {
                ans+=left-height[i];
                i++;
                
                cout<<ans<<" ";
            }
        }
        return ans;
    }
};