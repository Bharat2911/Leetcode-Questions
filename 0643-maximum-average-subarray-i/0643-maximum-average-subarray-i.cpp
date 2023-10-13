class Solution {
public:
    //we will be using the sliding window to solve this question
    double findMaxAverage(vector<int>& nums, int k) {
        
        int ans=INT_MIN;
        
        int n=nums.size();
        
        int sum=0;
        
        
        int i=0;
        
        int j=0;
        
        while(j<n)
        {
            sum+=nums[j];
            
            if(j-i+1<k)//means window not hit
            {
                j++;
            }
            else if(j-i+1==k)//means window hit we get the ans and shrink the window
            {
                
                
                ans=max(ans,sum);
                
                //shrink the window
                
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans/(double)k;
    }
};