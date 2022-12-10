class Solution
{
    public:
        int maximumValue(vector<string> &strs)
        {

            priority_queue<int> pq;	//max heap
            int num = 0;

            for (auto itr: strs)
            {
                int a = 0;//keep the count of alphabet
                int d = 0;//keep the count of digit

                for (int i = 0; i < itr.length(); i++)
                {
                    if (isalpha(itr[i]))
                    {
                        a++;
                    }
                    else
                    {
                        d++;
                    }
                }

                if (a == 0 and d > 0)
                {
                    // for (auto x: itr)
                    // {
                    //     num = num *10 + x - '0';
                    // }
                    // pq.push(num);
                    // num = 0;
                    
                    pq.push(stoi(itr));
                }
                else
                {
                    pq.push(itr.length());
                }
            }
            return pq.top();
        }
};