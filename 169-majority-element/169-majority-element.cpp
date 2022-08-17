class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //majority_elemnt jo bhi hoga vo maximum times apperar ho rha hoga or in sort vo maximum space occupy kar rha hoga
        int n=nums.size();
        int count=0;
        int ele=0;
        
        for(int i=0;i<n;i++)
        {
            if(count==0)ele=nums[i];
            
            if(ele==nums[i])count++;
            else count--;
        }
        return ele;
    }
};