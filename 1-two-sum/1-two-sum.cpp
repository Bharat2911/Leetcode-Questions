class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {

            unordered_map<int, int> map;
            vector<int> ans;

           	//store the index in the map
            for (int i = 0; i < nums.size(); i++)
            {
                map[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); i++)
            {
                int x = target - nums[i];

                if (map.find(x) != map.end())
                {
                    if (i != map[x])
                    {
                        ans.push_back(i);
                        ans.push_back(map[x]);
                        break;
                    }
                }
            }
            return ans;
        }
};