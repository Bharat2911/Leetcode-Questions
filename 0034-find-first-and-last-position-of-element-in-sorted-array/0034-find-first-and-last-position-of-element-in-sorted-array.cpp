class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //approach 1->linear searching we will do here
        //approch 2->we can do this using the binary searching
        
        int n=nums.size();
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                ans.push_back(i);
                break;
            }
            
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==target)
            {
                ans.push_back(i);
                break;
            }
        }
        if(ans.size()==1)
        {
            ans.push_back(-1);
        }
        
        return ans;
    }
};