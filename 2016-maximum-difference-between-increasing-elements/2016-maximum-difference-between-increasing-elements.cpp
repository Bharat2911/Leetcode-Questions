class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        //same as buy and sell stock
        //store thre minimum till taht point
        
        int ans=nums[0];
        int res=0;
        
        for(int i=1;i<nums.size();i++)
        {
            //store the  minimum till that point
            
            ans=min(ans,nums[i]);
            res=max(res,nums[i]-ans);
            
        }
        if(res==0)return -1;
        return res;
    }
};