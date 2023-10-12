class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        //approch 1-> T.C->O(n^3)
        //         -> S.C->O(1);
        
        
        //approch 2->T.C->O(n)
        //         ->S.C->O(n)
        
        int n=nums.size();
        
        vector<int>left(n);
        vector<int>right(n);
        
        left[0]=nums[0];
        
        right[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            left[i]=min(left[i-1],nums[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],nums[i]);
        }
        
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>left[i-1] and nums[i]<right[i+1])
            {
                return true;
            }
        }
        return false;
    }
};