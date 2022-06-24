class Solution
{
    public:
        bool isPossible(vector<int> &target)
        {

            priority_queue<int> pq;

            long long  total_sum = 0;
            
            if(target.size()==1 and target[0]!=1)return false;
            if(target.size()==1 and target[0]==1)return true;
            
            for (auto itr: target)
            {
                pq.push(itr);
                total_sum += itr;
            }

            while (!pq.empty())
            {
                int max_ele = pq.top();
                pq.pop();

                long long remaining_total = total_sum - max_ele;

                if (max_ele == 1 || remaining_total == 1)
                {
                    return true;
                }

                if (max_ele == 0 || max_ele < remaining_total)
                {
                    return false;
                }

                int updated_max = (int)(max_ele % remaining_total);

               	// corner case

                if (updated_max == 0)
                {
                    return false;
                }

                pq.push(updated_max);

                total_sum=updated_max+remaining_total;
            }

            return true;
        }
};