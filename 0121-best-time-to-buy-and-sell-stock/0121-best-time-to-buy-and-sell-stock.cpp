class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        int mini=prices[0];
        
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            
            maxi=max(maxi,prices[i]-mini);
        }
        
        if(maxi==INT_MIN)return 0;
        return maxi;
        
    }
};