class Solution
{
    public:
        bool isNStraightHand(vector<int> &nums, int k)
        {
            map<int, int> mp;
           	//count frequency of elements
            for (int n: nums)
                mp[n]++;

            int count = 0;
            while (mp.size() >= 1)
            {
                int cur = mp.begin()->first;
                while (count++<k)
                {
                   	// If cur element is not present then you have to return directly because its impossible to split completely
                    if (mp.find(cur) == mp.end())
                        return false;
                   	//after using cur we will reduce cur freq by 1 
                    mp[cur]--;
                   	// after accepting cur if freq become zero erase element
                    if (mp[cur] == 0)
                        mp.erase(cur);
                    cur++;
                }
                count = 0;
            }
            return mp.size() == 0;
        }
};