class Solution
{
    public:
        string digitSum(string s, int k)
        {

           	//doing this using recursion
            int n = s.length();

           	//bae case
            if (n <= k) return s;

            int sum = 0;
            int count = 0;
            string ans;

            for (int i = 0; i < n; i += k)
            {

                for (int j = i; j < i + k and j < n; j++)
                {
                    sum += s[j] - '0';
                }

                ans += to_string(sum);
                sum = 0;
            }

            return digitSum(ans, k);
        }
};