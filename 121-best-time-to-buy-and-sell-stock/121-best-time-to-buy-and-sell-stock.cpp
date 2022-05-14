class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        //so iwill be traking the min_price till date
        int min_price=nums[0];
        int max_profit=0;
        
        for(int i=0;i<nums.size();i++)
        {
            min_price=min(min_price,nums[i]);
            
            max_profit=max(max_profit,nums[i]-min_price);
        }
        return max_profit;
    }
};