class Solution
{
    public:
        static bool comp(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }

    int scheduleCourse(vector<vector < int>> &courses)
    {
        sort(courses.begin(), courses.end(), comp);	
        priority_queue<int> pq;
        int x = 0, count = 0;
        for (auto course: courses)
        {
           	
            if (x + course[0] <= course[1])
            {
                x += course[0];
                pq.push(course[0]);
                count++;	
            }
         
            else if (!pq.empty() && pq.top() >= course[0])
            {
                x = x - pq.top() + course[0];
                pq.pop();
                pq.push(course[0]);
               	
            }
        }
        return count;
    }
};