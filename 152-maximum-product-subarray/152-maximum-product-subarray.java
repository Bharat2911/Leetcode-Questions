class Solution {
    public int maxProduct(int[] nums) {
         int max = nums[0];
        int min = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < nums.length; i++){
            int maxProduct = Math.max(nums[i], nums[i] * max);
            int minProduct = Math.min(nums[i], nums[i] * min);
            
			//in case of negative number flips the max and min
            maxProduct = Math.max(maxProduct, nums[i] * min); 
            minProduct = Math.min(minProduct, nums[i] * max);
            
            max = maxProduct;
            min = minProduct;
            
            ans = Math.max(ans, max);
        }
        
        return ans;
    }
}