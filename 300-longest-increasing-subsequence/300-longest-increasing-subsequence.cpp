class Solution {
public:
    //T.C=O(n log n)
    // /s.C=O(1)
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>temp;
        
        temp.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                //apply binary search and re write it
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();//this will give index
                
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
};