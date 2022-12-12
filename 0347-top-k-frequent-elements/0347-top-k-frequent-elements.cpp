class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {

            unordered_map<int, int> map;	//used to store the frequency of each elements

            for (auto itr: nums)
            {
                map[itr]++;
            }
           	//min heap to find the top mose frequent k elemnts

            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;

            for (auto itr: map)
            {
                pq.push({ itr.second,
                    itr.first });
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }

            vector<int> ans;

            while (!pq.empty())
            {
                int top = pq.top().second;
                pq.pop();

                ans.push_back(top);
            }

            return ans;
        }
};