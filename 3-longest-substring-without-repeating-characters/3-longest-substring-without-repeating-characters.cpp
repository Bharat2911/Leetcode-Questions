class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {

           	//usign the map we will be doing thsi ,,map and sliding window
            int n = s.length();
            unordered_map<char, int> map;

            int i = 0;
            int j = 0;
            int ans = 0;

            while (j < n)
            {
                map[s[j]]++;

               	//two case
               	//if map size()==elemnets coveres sofar then we have the answer

                while (map.size() < j - i + 1)
                {
                    map[s[i]]--;

                    if (map[s[i]] == 0)
                    {
                        map.erase(s[i]);
                    }
                    i++;
                }
                if (map.size() == j - i + 1)
                {
                    ans = max(j - i + 1, ans);
                }
                j++;
            }
            return ans;
        }
};