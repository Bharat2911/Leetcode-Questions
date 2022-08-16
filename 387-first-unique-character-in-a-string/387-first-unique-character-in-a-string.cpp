class Solution
{
    public:
        int firstUniqChar(string s)
        {

            vector<int> freq(26, 0);

            for (auto itr: s)
            {
                freq[itr - 'a']++;	//askii value
            }

            for (int i = 0; i < s.length(); i++) 
            {
                if(freq[s[i]-'a']==1)
                {
                    return i;
                    break;
                }
            }
            return -1;
        }
};