class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
     int n=nums.size();
        vector<long long int>pre(n,0);
        vector<long long int>suff(n,0);
        
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        
        for(long long int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
          
        }
        
        for(long long int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+nums[i];
            
        }
        
        int count=0;
        
        for(long long int i=0;i<n-1;i++)
        {
            long long int  left=pre[i];
            long long int  right=suff[i+1];
            if(left>=right){
                count++;
            }
        }
        return count;
    }
};