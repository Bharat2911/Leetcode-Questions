class Solution {
public:
    bool solve(int idx,vector<int>&nums,int k,int curr_sum,int sum, vector<int>&vis)
    {
        //base case
        if(k==0)return true;
        
        if(curr_sum>sum)return false;
        
        if(curr_sum==sum)
        {
            return solve(0,nums,k-1,0,sum,vis);
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            if(vis[i])continue;
            
            vis[i]=1;
            
            if(solve(i+1,nums,k,curr_sum+nums[i],sum,vis))return true;
            
            vis[i]=0;
            
            if(curr_sum==0)break;
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum=0;
        
        int n=nums.size();
        
        for(auto itr:nums)
        {
            sum+=itr;
        }
        
        if(sum%k!=0)return false;
        
        if(nums.size()<k)return false;
        
        int idx=0;
        
        int curr_sum=0;
        
        sum=sum/k;
        
        vector<int>vis(n,0);
        
        return solve(idx,nums,k,curr_sum,sum,vis);
    }
};