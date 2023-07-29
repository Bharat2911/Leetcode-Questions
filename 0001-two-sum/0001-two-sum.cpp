class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //brute force approach 
        //T.C-> O(n^2);
        //S.C-> O(1);
        
        //optimised approach 
        //T.C->O(n);
        //S.C->O(n);//since we are usng the map
        int n=nums.size();
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                  ans.push_back(i);
                  ans.push_back(j);
                }
            }
        }
        return ans;
    }
};