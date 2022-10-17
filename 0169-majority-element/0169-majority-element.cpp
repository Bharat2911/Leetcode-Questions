class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //same as mores voting algorithmn 
        int n=nums.size();
        
        int count=0;
        int prev=0;
        
        for(int i=0;i<n;i++)
        {
            if(count==0)prev=nums[i];
            
            if(prev==nums[i])count++;
            else count--;
        }
        
        return prev;
    }
};