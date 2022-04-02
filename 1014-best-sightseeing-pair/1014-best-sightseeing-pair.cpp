class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int ans=0;
        
        int maxi=values[0]+0;
        
        for(int i=1;i<values.size();i++)
        {
            ans=max(ans,maxi+values[i]-i);
            maxi=max(maxi,values[i]+i);
        }
        return ans;
    }
};