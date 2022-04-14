class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(nums.size()<4)return{};
        
        vector<vector<int>>res;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1;
                int z=n-1;
                
                while(k<z)
                {
                    int sum=(long long)nums[i]+nums[j]+nums[k]+nums[z];
                    
                    if(sum<target)
                    {
                        k++;
                    }
                    else if(sum>target)
                    {
                        z--;
                    }
                    else
                    {
                        res.push_back({nums[i],nums[j],nums[k],nums[z]});
                        k++;
                        z--;
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};