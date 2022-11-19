class Solution
{
    public:
        int countSubstrings(string s)
        {

            int n = s.length();

            int start = 0;
            int end = 1;
            int count = 0;

            for (int i = 0; i < n; i++)
            {
               	//odd length
                int low = i ;
                int high = i;

                while (low >= 0 and high < n and s[low] == s[high])
                {

                    low--;
                    high++;
                    count++;
                }

               	//even case

                low = i ;
                high = i+1;

                while (low >= 0 and high < n and s[low] == s[high])
                {

                    low--;
                    high++;
                    count++;
                }
            }
            return count;
        }
};