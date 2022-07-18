class Solution
{
    public:
        bool validPalindrome(string s)
        {

            int n = s.length();
            int low = 0;
            int high = n - 1;
            int count = 0;

            while (low < high)
            {
                if (s[low] == s[high])
                {
                    low++;
                    high--;
                }
                else
                {
                    low++;
                    count++;
                }
            }
            if (count == 0 || count == 1) return true;

            low = 0;
            high = n - 1;
            count = 0;

            while (low < high)
            {
                if (s[low] == s[high])
                {
                    low++;
                    high--;
                }
                else
                {
                    high--;
                    count++;
                }
            }
            if (count == 0 || count == 1) return true;
            
            return false;
            
        }
};