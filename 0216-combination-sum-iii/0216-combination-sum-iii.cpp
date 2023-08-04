class Solution {
public:
    void solve(int idx,vector<vector<int>>&ans,vector<int>&res,int k,int sum)
    {
        if(idx==10)
        {
            if(sum==0)
            {
                
                if(res.size()==k)
                {
                    ans.push_back(res);
                }
            }
            return;
        }
        
        //pick
       
            res.push_back(idx);
            
            solve(idx+1,ans,res,k,sum-idx);
            
            //recursive call finisehd then undo the process we made
            
            res.pop_back();
        
        
        //not pick
        solve(idx+1,ans,res,k,sum);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        
        vector<int>res;
        
        int idx=1;
        
        solve(idx,ans,res,k,n);
        
        return ans;
    }
};