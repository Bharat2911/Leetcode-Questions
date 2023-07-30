class Solution {
public:
     int f(int i, int j, string& s, vector<vector<int>>& dp){       
        if (dp[i][j]) return dp[i][j];
        if (i==j) return dp[i][j]=1;
        int minPrint = 0;
        if (s[i]==s[j]) minPrint=f(i, j-1, s, dp);
        else{
            minPrint=f(i,j-1, s, dp)+1;
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j])
                    minPrint=min(minPrint, f(i, k-1, s, dp)+f(k, j-1, s, dp));
            }
        }
        return dp[i][j]=minPrint;
    }
    int strangePrinter(string s) {
       string sNew(1, s[0]);
       for(auto ch : s)
            if(ch != sNew.back())
                sNew.push_back(ch);
        int n = sNew.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return f(0, n-1, sNew, dp);
    }
};