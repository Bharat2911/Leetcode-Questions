class Solution {
public:
    int solve(vector<int>&nums,int sum)
    {
        int count=0;
        //minimum elemnts ko lo maximum lenght ke liye
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=sum)
            {
                count++;
                sum-=nums[i];
            }
        }
        return count;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        vector<int>ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int x=solve(nums,queries[i]);
            
            ans.push_back(x);
        }
        return ans;
    }
};