class Solution {
public:
    bool ispal(string&s,int low,int high)
    {
        while(low<high)
        {
            if(s[low++]!=s[high--])
            {
                return  false;
            }
        }
        return true;
    }
    void solve(int index,string &s,vector<vector<string>>&ans,vector<string>&res)
    {
        //base condtition
        ///followed by choice diagram 
        //forllowed by ans
        
        if(index==s.length())
        {
            ans.push_back(res);
            
            return;
        }
        
        //try each and every partition and check itis plaindrome or not
        
        for(int i=index;i<s.length();i++)
        {
            //if its is palindrome then we got out ans
            if(ispal(s,index,i))
            {
                res.push_back(s.substr(index,i-index+1));
                
                solve(i+1,s,ans,res);
                
                res.pop_back();//backtraking step 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        int index=0;
        vector<vector<string>>ans;
        vector<string>res;
        
        solve(index,s,ans,res);
        
        
        return ans;
    }
};