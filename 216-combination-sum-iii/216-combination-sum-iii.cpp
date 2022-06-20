class Solution
{
    public:
        
        void solve(int index,vector<int>&res,vector<vector<int>>&ans,int k,int sum)
        {
            if(index>10)
            {
                return;
            }
            if(res.size()==k )
            {
                if(sum==0)
                {
                    ans.push_back(res);
                }
                return;
            }
            
            //pick and not pick
            
            if(index<=sum)
            {
                res.push_back(index);
                solve(index+1,res,ans,k,sum-index);
                
                res.pop_back();//backtraking step
            }
            
            //not pick
            solve(index+1,res,ans,k,sum);
            
        }
        vector<vector < int>> combinationSum3(int k, int n) 
        {
            vector<int>res;
            vector<vector<int>>ans;
            
            int index=1;
            
            solve(index,res,ans,k,n);
            
            return ans;
        }
};