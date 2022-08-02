class Solution {
public:

    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int count=0;
        
        int i=0;
        int j=1;
        
        while(j<intervals.size())
        {
            if(intervals[i][1]>intervals[j][0])
            {
                count++;
                
                if(intervals[i][1]>=intervals[j][1])
                    i=j;
                j++;
            }
            else
            {
                i=j;
                j++;
                
            }
        }
        return count;
    }
};