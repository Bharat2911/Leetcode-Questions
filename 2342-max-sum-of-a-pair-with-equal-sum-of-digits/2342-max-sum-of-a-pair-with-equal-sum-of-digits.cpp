class Solution {
public:
    int sum_do(int num)
    {
        int sum=0;
        
        while(num>0)
        {
            int m=num%10;
            sum=sum+m;
            num=num/10;
        }
        return sum;
        
    }
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,vector<int>>map;
        
        for(int i=0;i<nums.size();i++)
        {
            int sum=sum_do(nums[i]);
            map[sum].push_back(nums[i]);
        }
        
        int ans=0;
        
        for(auto itr:map)
        {
            int sum=0;
            
            if(itr.second.size()>1)
            {
                sort(itr.second.begin(),itr.second.end());
                reverse(itr.second.begin(),itr.second.end());
                
                sum=itr.second[0]+itr.second[1];
            }
            ans=max(ans,sum);
        }
        if(ans==0)return -1;
        return ans;
    }
};