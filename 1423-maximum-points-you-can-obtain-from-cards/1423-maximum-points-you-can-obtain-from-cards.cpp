class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        //t.c ->O(n);
        //s.cO(1);
        
          int n=nums.size();
        int sum=0;
        int ans=0;
        
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        ans=sum;
        
        for(int i=0;i<k;i++)
        {
           sum-=nums[k-1-i];
            sum+=nums[n-i-1];
            
            
            ans=max(ans,sum);
        }
        return ans;
    }
};