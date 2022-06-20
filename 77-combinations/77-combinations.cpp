class Solution
{
    public:
        void solve(int index, vector<int> &res, vector<vector< int>> &ans, int n, int k)
        {
            if (index > n + 1)
            {
                return;
            }
            if (res.size() == k)
            {
                ans.push_back(res);
                return;
            }
            
            //pick
            res.push_back(index);
            solve(index+1,res,ans,n,k);
            
            //not pick
            
            res.pop_back();
            solve(index+1,res,ans,n,k);
            
            
        }
    vector<vector < int>> combine(int n, int k)
    {

        vector<vector < int>> ans;
        vector<int> res;

        int index = 1;

        solve(index, res, ans, n, k);

        return ans;
    }
};
//subsets
//subset 2
//combinational sum 
//cs 2
//cs 3
//combinations
//permutation
//permutaion 2