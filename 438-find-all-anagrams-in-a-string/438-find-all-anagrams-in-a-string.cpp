class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
           	//making the two freq array

            vector<int> for_s(26, 0);

            vector<int> for_p(26, 0);

            vector<int> ans;

            if (p.length() > s.length()) return {};

            int i = 0;
            int j = 0;

            int n = p.length();	//this is basically the window len

            while (j < n)
            {
                for_s[s[j] - 'a']++;	//askkii value keep in mind
                for_p[p[j] - 'a']++;
                j++;
            }
            j -= 1;

            while (j < s.length())
            {
                if (for_s == for_p)	//means there is ans
                {
                    ans.push_back(i);
                }
                j++;

                if (j != s.length())	//now shrink the window 
                {
                    for_s[s[j] - 'a']++;
                    for_s[s[i] - 'a']--;
                    i++;
                }
            }
            return ans;
        }
};