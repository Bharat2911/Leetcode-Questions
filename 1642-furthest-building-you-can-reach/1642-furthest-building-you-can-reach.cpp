class Solution
{
    public:
        int furthestBuilding(vector<int> &arr, int b, int l)
        {

            int n = arr.size();

           	//min heap
            int briksum=0;
            
            priority_queue<int, vector < int>, greater<int>> pq;
           
            

            for (int i = 0; i < n - 1; i++)
            {
                int diff = arr[i + 1] - arr[i];

                if (diff > 0)
                {
                    pq.push(diff);
                }

                if (pq.size() > l)
                {
                    briksum+=pq.top();
                    pq.pop();
                    
                }

                if (b < briksum)
                {
                    return i;
                }
            }
           	//if we reach the end then 
            return n - 1;
        }
};