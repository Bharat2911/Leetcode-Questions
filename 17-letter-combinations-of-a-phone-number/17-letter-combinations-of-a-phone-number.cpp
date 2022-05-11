class Solution {
public:
    vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int idx,string&digits,string &move,vector<string>&ans)
    {
        //base case
        if(idx==digits.length())
        {
            ans.push_back(move);
            return;
            
        }
        for(auto itr:map[digits[idx]-'0'])
        {
            move.push_back(itr);
            
            solve(idx+1,digits,move,ans);
            
            move.pop_back();
            
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        int index=0;
        vector<string>ans;
        string move;
        
        if(digits.length()==0)return{};
        
        
        solve(index,digits,move,ans);
        
        return ans;
    }
};