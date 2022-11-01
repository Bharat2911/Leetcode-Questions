class Solution {
public:
     int solve(vector<int>&nums)
    {
        int jump=1;
        int steps=nums[0];
        
        int max_reach=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(i==nums.size()-1)return jump;
            
            max_reach=max(max_reach,i+nums[i]);
            
            steps--;
            
            if(steps==0)
            {
                jump++;
                
                if(i>=max_reach)return -1;
                
                steps=max_reach-i;
            }
        }
         return steps;
    }
    bool canJump(vector<int>& nums) {
        
        if(nums.size()==1)return true;
        if(nums.size()>1 and nums[0]==0)return false;
        if(solve(nums)>0)return true;
        
        return false;
        
    }
};