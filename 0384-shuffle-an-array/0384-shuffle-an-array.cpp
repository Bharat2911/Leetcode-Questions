class Solution {
public:
    vector<int>res;
    
    void generate(int idx,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            
            generate(idx+1,ans,nums);
            
            swap(nums[idx],nums[i]);
        }
    }
       
    Solution(vector<int>& nums) {
        
        for(auto itr:nums)
        {
            res.push_back(itr);
        }
    }
    
    vector<int> reset() {
        
        return res;
    }
    
    vector<int> shuffle() {
        
       vector<int> shuffArr = res;
        int n=res.size();
        int last = n;
        for( int i = n-1; i>=0; i--){
            int ptr = rand()%last;
            swap(shuffArr[i], shuffArr[ptr]);
            last--;
        }
        return shuffArr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */