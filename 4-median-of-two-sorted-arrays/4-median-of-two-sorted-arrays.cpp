class Solution {
public:
    double solve(vector<int>&nums1,vector<int>&nums2,int n,int m,int k)
    {
        //bs will perform on the araay with minimum length
        if(m>n)
        {
            solve(nums2,nums1,m,n,k);
        }
        
        int low=max(0,k-m);
        int high=min(k,n);
        
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=k-cut1;
            
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            
            int r1=cut1==n?INT_MAX:nums1[cut1];
            int r2=cut2==m?INT_MAX:nums2[cut2];
            
            
            if(l1<=r2 and l2<=r1)
            {
                if((m+n)&1)
                {
                    return max(l1,l2);
                }
                else
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        int sum=n+m;
        
        int k=(sum+1)/2;
        
        return solve(nums1,nums2,n,m,k);
    }
};