class Solution {
public:
    int solve(int n)
    {
        int res=n*(n-1)*(n-2)*(n-3);
        
        res=res/24;
        
        return res;
    }
    int countVowelStrings(int n) {
        
        return solve(n+4);
    }
};