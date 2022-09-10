class Solution {
public:
    int mySqrt(int x) {
        
        //we will be applying binary search here
        int ans=0;
        
        int low=1;
        
        int high=x;
        
       while(low<=high)
       {
           int mid=low+(high-low)/2;
           
           if(mid<=x/mid)//----> mid^2<=x
           {
               ans=mid;
               low=mid+1;
           }
           else
           {
               high=mid-1;
               
           }
       }
        return ans;
    }
};