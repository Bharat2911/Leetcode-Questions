class Solution
{
    public:
        int minStoneSum(vector<int> &piles, int k)
        {

            int n = piles.size();

            priority_queue<int> pq;

            for (auto itr: piles)
            {
                pq.push(itr);
            }

            while (k--)
            {
                int top = pq.top();
                pq.pop();

                if (top & 1)//if odd  then half and add one
                {
                    top = top / 2;
                    top = top + 1;
                }
                else
                {
                    top = top / 2;//if even then simply half
                }

                pq.push(top);
            }
            int sum = 0;

            while (pq.size() > 0)
            {
                sum += pq.top();
                pq.pop();
            }
            return sum;
        }
};