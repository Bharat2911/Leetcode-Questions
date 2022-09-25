class Solution
{
    public:
        vector<string> sortPeople(vector<string> &names, vector<int> &heights)
        {

            vector<pair<int, string>> ans;

            for (int i = 0; i < names.size(); i++)
            {
                ans.push_back({ heights[i],
                    names[i] });
            }
            sort(ans.begin(), ans.end(), greater < > ());

            vector<string> v;

            for (int i = 0; i < ans.size(); i++)
            {
                v.push_back(ans[i].second);
            }
            return v;
        }
};