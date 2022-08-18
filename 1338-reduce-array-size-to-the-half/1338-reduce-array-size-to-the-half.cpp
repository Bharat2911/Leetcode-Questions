class Solution
{
    public:
        int minSetSize(vector<int> &arr)
        {

            int n = arr.size();
            
            if(n==2)return 1;
            
            unordered_map<int, int> map;

            priority_queue<pair<int, int>> pq;	//basically this is the max heap

            for (auto itr: arr)
            {
                map[itr]++;
            }

            for (auto itr: map)
            {
                pq.push({ itr.second,
                    itr.first });
            }

            int count = 0;
            int ans=0;
            

            while (!pq.empty() )
            {
                int freq=pq.top().first;
                int ele=pq.top().second;
                
                pq.pop();
                
                count+=freq;
                ans++;
                
                if(count>=n/2)return ans;
            }
            return ans;
        }
};