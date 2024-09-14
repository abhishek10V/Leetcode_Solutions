class Solution {
    public int longestSubarray(int[] nums) {
        int maxVal = 0;
        int res = 0;
        int streak = 0;

        for(int n : nums){
            if(n > maxVal){
                maxVal = n;
                streak = 0;
                res = 0;
            }
            if(maxVal == n) streak++;
            else streak=0;

            res = Math.max( res , streak);
        }
        return res;
    }
}