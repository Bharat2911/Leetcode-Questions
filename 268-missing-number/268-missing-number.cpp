class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int count=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=count)return count;
            else
            {
                count++;
            }
        }
        return count;
    }
};