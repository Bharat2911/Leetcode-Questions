class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        
        int n=c.size();
        
        vector<int>nums;
        
        for(int i=0;i<n;i++)
        {
            nums.push_back(c[i]-r[i]);
        }
        
        sort(nums.begin(),nums.end());
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(ar>=nums[i])
            {
                count++;
                ar=ar-nums[i];
            }
        }
    
       return count;
    }
};