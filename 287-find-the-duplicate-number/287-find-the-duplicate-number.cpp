class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       //if the particular elemnt is already seen before means it is repeating 
        
        int n=nums.size();
        
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[nums[i]])
            {
                vis[nums[i]]=1;
            }
            else
            {
                return nums[i];
            }
        }
        return -1;
    }
};