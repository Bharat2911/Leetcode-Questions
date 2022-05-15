class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
     int n=nums.size();
        vector< long long int> pre(n,0),suf(n,0);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(long long int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(long long int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
        }
       int ans=0;
        for(long long int i=0;i<n-1;i++){
          long long int  left=pre[i];
            long long int  right=suf[i+1];
            if(left>=right){
                ans++;
            }
        }
        return ans;
    }
};