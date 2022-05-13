class Solution {
    private:
      bool checker(vector<int>&nums,int start,int end)
      {
          for(int i=start;i<end;i++)
          {
              if(nums[i]==nums[end])return 0;
          }
          return 1;
          
      }
    private: 
     void solve(int index,vector<int>&nums,vector<vector<int>>&ans)
     {
         if(index==nums.size())
         {
             ans.push_back(nums);
             return;
         }
         for(int i=index;i<nums.size();i++)
         {
             bool check=checker(nums,index,i);
             
             if(check)
             {
                 swap(nums[index],nums[i]);
                 solve(index+1,nums,ans);
                 swap(nums[index],nums[i]);
                 
             }
         }
     }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        solve(0,nums,ans);
        
        return ans;
        
    }
};