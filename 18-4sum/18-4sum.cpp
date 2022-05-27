class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //now optimised it 
        //t.c->O(n^3);
        int n=nums.size();
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        //couple of base case
        
        if(n<4)return ans;
        
       
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1;
                int x=n-1;
                
                while(k<x)
                {
                    int sum=(long long )nums[i]+nums[j]+nums[k]+nums[x];
                    
                    
                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[x]});
                        
                        k++;
                        x--;
                    }
                    else if(sum>target)
                    {
                        x--;
                    }
                    else
                    {
                        k++;
                    }
                    
                    
                    
                }
            }
        }
        sort(ans.begin(),ans.end());
          ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
        
    }
};