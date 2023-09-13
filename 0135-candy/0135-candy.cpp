class Solution {
public:
    int candy(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>c_left(n,1);
        
        vector<int>c_right(n,1);
        
        //filling the left one
        
        for(int i=1;i<n;i++)
        {
          
           if(nums[i]>nums[i-1])
           {
               c_left[i]=1+c_left[i-1];
           }
        }
        
        //filling the right
        
        for(int i=n-2;i>=0;i--)
        {
           if(nums[i]>nums[i+1])
           {
               c_right[i]=1+c_right[i+1];
           }
        }
        
        // for(auto itr:c_right)
        // {
        //     cout<<itr<<" ";
        // }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans+=max(c_left[i],c_right[i]);
        }
        
        return ans;
        
    }
};