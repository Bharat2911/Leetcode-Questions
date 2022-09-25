class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<int>pre(n,1);
        vector<int>suff(n,1);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                pre[i]=pre[i-1]+1;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            {
                suff[i]=suff[i-1]+1;
            }
        }
        
        vector<int>ans;
        
        for(int i=1;i<(n-k);i++)
        {
            int x1=pre[i-1];
            int x2=suff[i+k];
            
            if(x1>=k and x2>=k)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};