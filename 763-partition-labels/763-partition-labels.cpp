class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {

           	//T.C=o(n)
           	//S.C=O(n)

           	//approach to store the last instance of each character
            int n = s.length();

            unordered_map<char, int> map;

            for (int i = 0; i < n; i++)
            {
                map[s[i]] = i;
            }

            vector<int> ans;

            int start = 0;
            int end = 0;

            for (int i = 0; i < n; i++)
            {
                end = max(end, map[s[i]]);

                if (i == end)
                {
                    ans.push_back(end - start + 1);

                    start = i + 1;	//reset the start since i have taken my one substring
                }
            }
            return ans;
        }
};