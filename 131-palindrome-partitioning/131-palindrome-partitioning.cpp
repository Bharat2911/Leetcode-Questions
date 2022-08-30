class Solution {
public:
    bool ispal(string&s,int low,int high)
    {
        while(low<=high)
        {
            if(s[low++]!=s[high--])
            {
                return false;
            }
        }
        return true;
        
    }
    void solve(int idx,string&s,vector<vector<string>>&ans,vector<string>&res)
    {
        if(idx==s.length())
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx;i<s.length();i++)
        {
            if(ispal(s,idx,i))
            {
                res.push_back(s.substr(idx,i-idx+1));
                
                solve(i+1,s,ans,res);
                
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string>res;
        
        int idx=0;
        
        solve(idx,s,ans,res);
        
        return ans;
         
    }
};