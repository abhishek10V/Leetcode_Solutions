class Solution {
    public int firstMissingPositive(int[] nums) {
        int in = -1;
       for(int i=0 ; i<nums.length; i++){
        if(nums[i] != 1) in  = i;
        else break;
       }
       if(in == nums.length - 1) return 1;
       else{
         transform(nums);
         for(int i=0; i<nums.length; i++){
            int val = Math.abs(nums[i]);
            int idx = val - 1;

            if(nums[idx] > 0)
            nums[idx] = -nums[idx];
         }

         for(int i=0 ; i<nums.length; i++){
            if(nums[i] > 0) return i + 1;
         }
       }
       return nums.length + 1;
    }
    public void transform(int[] nums){
       int n = nums.length;
       for(int i=0 ;i<n ; i++){
         if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
       }
    }
}