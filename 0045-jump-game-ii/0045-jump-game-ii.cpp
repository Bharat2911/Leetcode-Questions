class Solution {
public:
    int solve(vector<int>&nums,int n)
    {
        int jump=1;
        int steps=nums[0];
        int max_range=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1)return jump;
            
            max_range=max(max_range,i+nums[i]);
            
            steps--;
            
            if(steps==0)
            {
                jump++;
                
                if(i>=max_range)return -1;
                
                steps=max_range-i;
            }
        }
        return steps;
    }
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)return 0;
        
        return solve(nums,n);
    }
};