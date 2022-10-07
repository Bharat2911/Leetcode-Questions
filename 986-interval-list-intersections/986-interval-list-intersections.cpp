class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        
        
        vector<vector<int>>ans;
        
        int n=list1.size();
        int m=list2.size();
     
        
        int i=0;
        int j=0;
        
        while(i<n and j<m)
        {
            int start=max(list1[i][0],list2[j][0]);
            
            int end=min(list1[i][1],list2[j][1]);
            
            if(start<=end)
            {
                ans.push_back({start,end});
            }
            
            if(list1[i][1]<list2[j][1])i++;
            else j++;
        }
        return ans;
    }
};