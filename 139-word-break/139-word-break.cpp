class Solution
{
    public:
        int dp[301];
    
        bool solve(int index, string &A, vector<string> &B)
        {
           	//base case
            if (index == A.length())
            {
                return true;
            }
            if(dp[index]!=-1)
            {
                return dp[index];
            }
            for (auto itr: B)
            {
                int l = itr.length();

               	// a ki same length ke substr
                string str = A.substr(index, l);

                if (str == itr)
                {
                    if (solve(index + l, A, B)) return dp[index]=true;
                }
            }
            return dp[index]=false;
        }
    bool wordBreak(string s, vector<string> &wd)
    {

       	//writing the recursive function
       memset(dp,-1,sizeof dp);
        int index = 0;

        return solve(index, s, wd);
    }
};