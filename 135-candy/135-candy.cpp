class Solution
{
    public:
        int candy(vector<int> &arr)
        {
            int sum = 0;
            int n = arr.size();
            vector<int> cand(n, 1);

            for (int i = 1; i < n; i++)
            {
                if (arr[i] > arr[i - 1])
                {
                    cand[i] = cand[i - 1] + 1;
                }
            }
            for (int i = n - 2; i >= 0; i--)\
            {

                if (arr[i] > arr[i + 1] and cand[i] <= cand[i + 1])
                {
                    cand[i] = cand[i + 1] + 1;
                }
            }
            for (auto itr: cand)
            {
                cout << itr << " ";
                sum += itr;
            }

            return sum;
        }
};