class Solution {
public:
   vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
    void solve(int index,string&digits,string&moves,vector<string>&ans)
    {
        //bae case
        if(index==digits.size())
        {
            ans.push_back(moves);
            return;
        }
        
        //itrate in the map
        for(auto itr:map[digits[index]-'0'])
        {
            moves.push_back(itr);
            solve(index+1,digits,moves,ans);
            moves.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        string moves;
        
        if(digits.length()==0)return ans;
        
        solve(0,digits,moves,ans);
        
        return ans;
        
    }
};