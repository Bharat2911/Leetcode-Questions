class Solution
{
    public:
        int minDeletions(string s)
        {

            int n = s.length();

            unordered_map<char, int> map1;

           	//storing the freq of each char in the map

            for (auto itr: s)

            {
                map1[itr]++;
            }

            unordered_map<int, bool> map2;

            int ans = 0;

            for (auto itr: map1)
            {

                while (map2.find(itr.second) != map2.end()) 
                {
                    itr.second--;
                    ans++;
                }
                if(itr.second>0)
                {
                    map2[itr.second]=true;
                }
            }
            return ans;
        }
};