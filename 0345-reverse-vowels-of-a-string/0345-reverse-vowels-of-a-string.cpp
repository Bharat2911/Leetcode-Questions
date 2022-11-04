class Solution
{
    public:
        string reverseVowels(string s)
        {

            int n = s.length();

            vector<char> v;

            for (auto itr: s)
            {
                if (itr == 'a' || itr == 'e' || itr == 'i' || itr == 'o' || itr == 'u' || itr == 'A' || itr == 'E' || itr == 'I' || itr == 'O' || itr == 'U')
                {
                    v.push_back(itr);
                }
            }

            reverse(v.begin(), v.end());

            string ans = "";
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                {

                    ans += v[j];
                    j++;
                }
                else
                {
                    ans += s[i];
                }
            }
            return ans;
        }
};