class Solution
{
    public:
        string reorganizeString(string s)
        {

            int n = s.length();
            priority_queue<pair<int, char>> pq;

            unordered_map<char, int> map;
            for (auto itr: s)
            {
                map[itr]++;
            }

            for (auto itr: map)
            {
                pq.push({ itr.second,
                    itr.first });
            }
            string ans = "";
            if (pq.size() == 0) return ans;

            while (pq.size() > 1)
            {
                int f1 = pq.top().first;
                char ele1 = pq.top().second;

              

                ans += ele1;
                
                pq.pop();
                int f2 = pq.top().first;
                char ele2 = pq.top().second;

                ans += ele2;
                pq.pop();
                

                if (f1>1)
                {
                    pq.push({f1-1,ele1});
                }
                if(f2>1)
                {
                    pq.push({f2-1,ele2});
                }

            }
            if(pq.size()==1 and pq.top().first==1)
            {
                ans+=pq.top().second;
            }
            if(pq.size()==1 and pq.top().first>1)
            {
                return "";
                
            }
            return ans;
        }
};