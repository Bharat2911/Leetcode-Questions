class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans,vector<int>&res)
    {
        ans.push_back(res);
        
        for(int i=idx;i<nums.size();i++)
        {
             if(i!=idx && nums[i] == nums[i-1]) continue; 
            res.push_back(nums[i]);
            solve(i+1,nums,ans,res);
            res.pop_back();//backtraking steps
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        //use the set to remove the duplicates but that will cuse the space complexitiy to O(n)
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(),nums.end());
        int idx=0;
        
        solve(idx,nums,ans,res);
        
        return ans;
    }
};