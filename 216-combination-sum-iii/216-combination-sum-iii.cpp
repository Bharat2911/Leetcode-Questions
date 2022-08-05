class Solution {
public:
    void solve(int idx,int k,int n,vector<vector<int>>&res,vector<int>&ans)
    {
        if(idx>10)
        {
            return;
        }
        
        if(ans.size()==k and n==0)
        {
            res.push_back(ans);
            return;
        }
        
        //pick
        if(idx<=n)
        {
            ans.push_back(idx);
            
            solve(idx+1,k,n-idx,res,ans);
            
            ans.pop_back();
        }
        
        solve(idx+1,k,n,res,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        
        
        int idx=1;
        
        vector<vector<int>>res;
        vector<int>ans;
        
        int sum=0;
        
        solve(idx,k,n,res,ans);
        
         set<vector<int>>set;
        
        for(auto itr:res)
        {
            set.insert(itr);
        }
        
         vector<vector<int>>v;
        
        for(auto itr:set)
        {
            v.push_back(itr);
        }
        return v;
    
    }
};