class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &changed)
        {

            int n = changed.size();

            sort(changed.begin(), changed.end());
            unordered_map<int, int> map;

            if (changed.size() % 2 != 0)
            {
                return {};
            }
            for (auto itr: changed)
            {
                map[itr]++;
            }
            vector<int> ans;

            for (auto itr: changed)
            {
                if (map[itr] == 0) continue;

                if (map[itr *2] == 0)
                {
                    return {};
                }

                ans.push_back(itr);

                map[itr]--;
                map[itr *2]--;
            }
            return ans;
        }
};