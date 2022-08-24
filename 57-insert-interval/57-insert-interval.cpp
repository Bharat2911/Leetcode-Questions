class Solution
{
    public:
       	//T.C=O(n log n);
       	//S.C=O(1);

        vector<vector < int>> insert(vector<vector < int>> &intervals, vector< int > &newInterval)
        {

            intervals.push_back(newInterval);

            vector<vector < int>> ans;

            if (intervals.size() == 0)
            {
                return ans;
            }
            sort(intervals.begin(), intervals.end());

           	//now question boils down to merge intervals

            int l = intervals[0][0];
            int r = intervals[0][1];

            for (int i = 1; i < intervals.size(); i++)
            {
                if (r >= intervals[i][0])
                {
                   	//update r as we are getting interval that are merging af
                    r = max(r, intervals[i][1]);
                }
                else
                {
                    ans.push_back({ l, r });

                   	//uodate l and r
                    l = intervals[i][0];
                    r = intervals[i][1];
                }
               	//bache hue intervals ko daal do

            }
            ans.push_back({ l,
                r });
            return ans;
        }
};