class Solution {
public:
    int solve(vector<int>&nums,int i,int j)
    {
        if(i>j)
        {
            return 0;
        }
        
//when p1 pick from either end then player 2 can pick from starting end or ending end from the   remaning array , player 2 will try to pick the maximum and try to give us the minimum in order to win
        
        
        int start=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));//when p1 pick from starting end 
        
        int end=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));//when p2 pick from ending end
        
        return max(start,end);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        int total_sum=0;
        
        int i=0;
        int j=n-1;
        
        for(auto itr:nums)
        {
            total_sum+=itr;
            
        }
        
        int score_p1=solve(nums,i,j);
        
        int score_p2=total_sum-score_p1;
        
        if(score_p2<score_p1 || score_p1==score_p2)return true;
        
        else return false;
        
    }
};