class Solution
{
    public:
        vector<int> rearrangeBarcodes(vector<int> &nums)
        {

            unordered_map<int, int> map;

            priority_queue<pair<int, int>> pq;

            for (auto itr: nums)
            {
                map[itr]++;
            }

            for (auto itr: map)
            {
                pq.push({ itr.second,
                    itr.first });
            }

            vector<int> ans;

            while (pq.size() > 1)
            {

                int f1 = pq.top().first;
                int i1 = pq.top().second;

                ans.push_back(i1);

                pq.pop();

                int f2 = pq.top().first;
                int i2 = pq.top().second;

                ans.push_back(i2);

                pq.pop();

                if (f1 > 1)
                {
                    pq.push({ f1 - 1,
                        i1 });
                }
                if (f2 > 1)
                {
                    pq.push({ f2 - 1,
                        i2 });
                }
            }
            if (!pq.empty() and pq.top().first == 1)
            {
                ans.push_back(pq.top().second);
            }
            return ans;
        }
};