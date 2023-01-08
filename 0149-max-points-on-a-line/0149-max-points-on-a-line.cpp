class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        //for a point to lie on a line the slope must be equal and slope shpuld be unique
        int res=0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int samePnt=1;
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0]==points[j][0] and points[i][1]==points[j][1])
                {
                    samePnt++;
                }
                else if(points[i][0]==points[j][0])
                {
                    mp[INT_MAX]++;
                }
                else
                {
                    double slope=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            int currMax=0;
            for(auto &i:mp)
            {
                currMax=max(currMax,i.second);
            }
            currMax+=samePnt;
            res=max(res,currMax);
        }
        return res;
    }
};