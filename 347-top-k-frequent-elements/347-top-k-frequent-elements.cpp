class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {

            int n = nums.size();

            unordered_map<int, int> map;

            for (int i = 0; i < n; i++)
            {
                map[nums[i]]++;
            }

            priority_queue<pair<int, int>> pq;

           	//pq ->(map.second,ele)

            for (auto itr: map)
            {
               	//since in pq ele arrange acc to the max frequency
                pq.push({ itr.second,
                    itr.first });
            }
            vector<int> ans;

            while (!pq.empty() and k > 0)
            {
                int first = pq.top().first;
                int second = pq.top().second;
                pq.pop();
                
                ans.push_back(second);
                
                k--;
            }
            return ans;
        }
};