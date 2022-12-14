class Solution {
public:
    int maxArea(vector<int>& arr) {
        
        int n=arr.size();
        
        int low=0;
        int high=n-1;
        
        int ans=INT_MIN;
        
        while(low<high)
        {
            int len=high-low;
            
            int area=min(arr[low],arr[high])*len;
            
            
            ans=max(ans,area);
            
            
            if(arr[low]<arr[high])
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