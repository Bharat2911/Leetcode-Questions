class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
        int previous=0;
        int count=0;
        
        for(int current=1;current<n;current++)
        {
            if(intervals[previous][1]>intervals[current][0])
            {
                //we ar ehaving the overlapping intervals int this 
                count++;
                
                if(intervals[previous][1]>intervals[current][1])
                {
                    previous=current;
                }
            }
            else
            {
                previous=current;
            }
        }
        
        return count;
    }
};