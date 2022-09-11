class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        //this is same as  minimum number of platforms
        
        vector<int>arr;
        vector<int>dep;
        
        int n=intervals.size();
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(intervals[i][0]);
            dep.push_back(intervals[i][1]);
        }
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int i=0;
        
        int j=1; 
        
        int count=1;
        
        while(j<n)
        {
            if(dep[i]>=arr[j])
            {
                count++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return count;
    }
};