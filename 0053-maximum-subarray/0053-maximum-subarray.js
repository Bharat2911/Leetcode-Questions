/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    
    var n=nums.length;
    
    var curr_sum=0;
    var ans=-999999999999999;
    
    for(var i=0;i<n;i++)
        {
            curr_sum=curr_sum+nums[i];
            
            ans=Math.max(ans,curr_sum);
            
            if(curr_sum<0)
                {
                    curr_sum=0;
                }
        }
    return ans;
};