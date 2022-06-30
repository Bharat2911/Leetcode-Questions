class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
       /*
         Approach 
         
         i will pick  a element from array itself ,try to make all the other elements of araay
         equal to that element
         
         i will pick a element in such a way that we get the minimum moves
         
         so will sort the array in increasing order and pick the middel of the array and try to 
         make all the other elements of the array equal to mid element
         
         WHY MID ELEMENT ??
         beacuse in the sorted array the mid element will have the least distance from all the
         other elements.
         
         T.C  =O(n log n); becoz of sorting 
         
         SD.C=O(1);
         
         
       */
        //sort 
        sort(nums.begin(),nums.end());
        
        int ans=0;
        
        int n=nums.size();
        
        int mid=nums[n/2];
        
        for(int i=0;i<n;i++)
        {
            ans+=abs(nums[i]-mid);
        }
        
        return ans;
    }
};