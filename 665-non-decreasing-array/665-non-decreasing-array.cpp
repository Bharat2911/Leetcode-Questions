class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        //when curr element is greater than next element than we have to modify the elment inorder to make array decreasing
        int n=nums.size();
        
        int count=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])//curr ele greater than next
            {
                count++;
                
            }
            // tackle corner case
            if(i-2>=0 and i+1<n and nums[i-2]>nums[i] and nums[i-1]>nums[i+1])return false;
        }
        if(count<2)return true;
        
        return false;
    }
};