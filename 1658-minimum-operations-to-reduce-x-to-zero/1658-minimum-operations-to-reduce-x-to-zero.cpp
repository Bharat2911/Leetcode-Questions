class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        unordered_map<int,int>mp; // {prefixSum,indexupto}
        int sum =0;
        mp[0] = -1; //for edge case 
        for(int i = 0; i<n; i++){
            sum+= nums[i];
            mp[sum] = i; // storing current sum in map
        }
        if(sum<x)return -1;
        int remainingSum = sum-x;
        int longestSubarraySum = INT_MIN;
        sum =0; //resetting the sum
        for(int i =0; i<n; i++){
            sum+=nums[i];
            int findSum = sum-remainingSum;
            if(mp.find(findSum) != mp.end()){
                int idx = mp[findSum];
                longestSubarraySum = max(longestSubarraySum,i-idx);

            }

        }
        return longestSubarraySum == INT_MIN ?-1 :(n-longestSubarraySum);
        
    }
};