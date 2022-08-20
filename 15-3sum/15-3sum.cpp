class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {

          //optimal approach yahi hai bhai 
            //o(n^2)
            
            int n=nums.size();
            
            vector<vector<int>>ans;
            
            sort(nums.begin(),nums.end());
            
            for(int i=0;i<n-1;i++)
            {
                int j=i+1;
                int k=n-1;
                
                if(i>0 and nums[i]==nums[i-1])continue;
                
               
                
                while(j<k)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        ans.push_back({nums[i],nums[j],nums[k]});
                        while(j<k and nums[j]==nums[j+1])j++;
                        while(j<k and nums[k]==nums[k-1])k--;
                        j++;
                        k--;
                    }
                    else if(nums[i]+nums[j]+nums[k]<0)
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