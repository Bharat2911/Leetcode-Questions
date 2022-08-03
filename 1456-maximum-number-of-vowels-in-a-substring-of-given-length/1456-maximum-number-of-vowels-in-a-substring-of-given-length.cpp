class Solution
{
    public:
        bool isvowel(char ch)
        {
           	//curr char is vowel or not 
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }
    int maxVowels(string s, int k)
    {

        int n = s.length();

        int ans = 0;

        int vowel = 0;

        int i = 0;
        int j = 0;

        while (j < n)
        {

            if (isvowel(s[j]))
            {
                vowel++;
            }

           	//window not hit

            if (j - i + 1 < k)
            {
                j++;	//expanding my window
            }

           	// window hit

            else if (j - i + 1 == k)
            {
               	//answer
                ans = max(ans, vowel);

               	//shrink the window

                if (isvowel(s[i]))
                {
                    vowel--;
                }

               	//move the window 

                i++;
                j++;
            }
        }
        return ans;
    }
};