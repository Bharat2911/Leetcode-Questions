class Solution {
public:
    bool ispal(int low,int high,string&s)
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
    void solve(int idx,vector<vector<string>>&ans,vector<string>&res,string&s)
    {
        if(idx==s.length())
        {
            ans.push_back(res);
            return;
        }
        
        //i have to loop out to get the partition point
        
        for(int i=idx;i<s.length();i++)
        {
            if(ispal(idx,i,s))
            {
                res.push_back(s.substr(idx,i-idx+1));
                
                solve(i+1,ans,res,s);
                
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        int idx=0;
        
        vector<vector<string>>ans;
        
        vector<string>res;
        
        solve(idx,ans,res,s);
        
        
        return ans;
        
    }
};