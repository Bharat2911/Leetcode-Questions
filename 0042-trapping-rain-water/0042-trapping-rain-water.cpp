class Solution {
public:
    int trap(vector<int>& arr) {
       
        //left se man and right se max
        
        
        int n=arr.size();
        
        int left_max=0;
        int right_max=0;
        
        int i=0;
        int j=n-1;
        
        int ans=0;
        
        while(i<j)
        {
            left_max=max(left_max,arr[i]);
            
            right_max=max(right_max,arr[j]);
            
            //now we have two cases
            
            if(left_max<right_max)
            {
                ans+=left_max-arr[i];
                
                i++;
            }
            else
            {
                ans+=right_max-arr[j];
                
                j--;
            }
        }
        return ans;
    }
};