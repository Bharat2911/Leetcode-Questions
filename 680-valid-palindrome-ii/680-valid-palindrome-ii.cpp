class Solution
{
    public:
        bool validPalindrome(string s)
        {

            int n = s.length();
            int i = 0;
            int j = n - 1;
            int count = 0;

            while (i < j)
            {
                if (s[i] == s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    i++;
                    count++;
                }
            }
            if (count == 1 || count==0) return true;
           
            
            i=0;
            j=n-1;
            count=0;
            
            while(i<j)
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    j--;
                    count++;
                }
            }
            if(count==0 || count==1)return true;
            
            return false;
        }
};