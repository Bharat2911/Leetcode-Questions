class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int mini=INT_MAX;
        int ans=INT_MAX;
        
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==target)
                {
                    return target;
                }
                else if(abs(sum-target)<mini)
                {
                    ans=sum;
                    mini=abs(sum-target);
                }
                else if(sum<target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};