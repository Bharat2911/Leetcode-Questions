class Solution
{
    public:
        void solve(int idx, vector<int> &nums, vector<vector< int >> &ans, vector< int > res)
        {
           	//base case
         ans.push_back(res);
            if(idx==nums.size())
            return;
            
           for(int i=idx;i<nums.size();i++)
           {
               res.push_back(nums[i]);
               solve(i+1,nums,ans,res);
               res.pop_back();
               
           }
            
            
        }
    vector<vector < int>> subsets(vector<int> &nums)
    {

       	//each elemnt have two options whether i will chose or will not choose
        vector<vector < int>> ans;

        vector<int> res;

        int idx = 0;

        solve(idx, nums, ans, res);

        return ans;
    }
};