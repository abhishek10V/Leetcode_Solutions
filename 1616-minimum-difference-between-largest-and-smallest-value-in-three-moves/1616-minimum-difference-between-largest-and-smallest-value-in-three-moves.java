class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if(n <= 4) return 0;
        Arrays.sort(nums);
       int minDiff = Integer.MAX_VALUE;
       int caseDiff = nums[n-4] - nums[0];
       minDiff = Math.min(minDiff , caseDiff);
       caseDiff = nums[n-3] - nums[1];
       minDiff = Math.min(minDiff , caseDiff);
       caseDiff  = nums[n-2] - nums[2];
       minDiff = Math.min(minDiff , caseDiff);
       caseDiff = nums[n-1] - nums[3];
       minDiff = Math.min(minDiff , caseDiff);

       return minDiff;
    }
}