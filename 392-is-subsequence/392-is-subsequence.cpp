class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {

            int n = s.length();
            int m = t.length();

            int i = 0;
            int j = 0;

            while (i < n and j < m)
            {
                if (s[i] == t[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            if(i==n)return true;
            return false;
        }
};