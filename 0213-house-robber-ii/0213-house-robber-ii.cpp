class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0,bob1=0, rob2=0,bob2=0;
        int n=nums.size();
        if(n==1) return nums[0];
        
     for(int i=0; i<n-1; i++){
          int temp=max(rob1+nums[i], rob2);
          rob1=rob2;
          rob2=temp;
        }
    for(int j=1;j<n; j++){
        int tempo=max(bob1+nums[j], bob2);
          bob1=bob2;
          bob2=tempo;
    }
        return max(rob2, bob2);
    }
};