class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k=nums.size();
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<k;i++)
        {
            int first_ele=nums[i][0];
            
            maxi=max(maxi,first_ele);
            mini=min(mini,first_ele);
            
            pq.push({first_ele,{i,0}});
        }
        int low=mini;
        int high=maxi;
        
        while(!pq.empty())
        {
            int mini=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(maxi-mini<high-low)
            {
                low=mini;
                high=maxi;
            }
            if(col+1<nums[row].size())
            {
                maxi=max(maxi,nums[row][col+1]);
                pq.push({nums[row][col+1],{row,col+1}});
            }
            else
            {
                break;
            }
        }
        return {low,high};
    }
};