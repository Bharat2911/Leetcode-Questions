class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
        int ans=0;
        
        int previous=0;
        
        for(int current=1;current<n;current++)
        {
            if(intervals[previous][1]>intervals[current][0])//we have a overlapping
            {
                //case arrive that which interval i have to remove
                
                ans++;//since i have to remove
                
                if(intervals[previous][1]>intervals[current][1])
                {
                    previous=current;//remove first one
                }
            }
            else
            {
                previous=current;
            }
        }
     return ans;   
    }
};