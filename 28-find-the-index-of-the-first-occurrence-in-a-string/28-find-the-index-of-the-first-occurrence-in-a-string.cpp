class Solution
{
    public:
        int strStr(string str, string s)
        {

            int k = s.length();

            if (s.length() == 0)
            {
                return -1;
            }
            if (str.length() == 0 and s.length() == 0)
            {
                return 0;
            }
            // if (str.length() == s.length())
            // {
            //     return 0;
            // }
            // if (s.length() > str.length())
            // {
            //     return -1;
            // }

            int i = 0;
            int j = 0;

            while (j < str.length())
            {
                if (j - i + 1 < k)	//case when window not hit
                {
                    j++;
                }
                else if (j - i + 1 == k)	//window get hit so in this case check for the answer
                {
                    if (str.substr(i, k) == s)
                    {
                       	//means match ho gya and answer aa rha hoga
                        return i;	//since i is the pointing to the starting character of the string
                    }
                    i++;
                    j++;
                }
            }
            return -1;
        }
};