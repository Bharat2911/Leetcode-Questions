class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int target=0;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n-2;i++)
        {
            if(i>0 and nums[i]==nums[i-1])continue;
            
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    while(j<k and nums[j]==nums[j+1])j++;
                    
                    while(j<k and nums[k]==nums[k-1])k--;
                    
                    j++;
                    k--;
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