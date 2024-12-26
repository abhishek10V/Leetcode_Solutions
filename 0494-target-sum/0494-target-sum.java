class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int S = 0;
        int n = nums.length;

        for(int i=0 ; i<n; i++) S += nums[i];

        int[][] dp = new int[n+1][2*S + 1];
        for(int[] row : dp) Arrays.fill(row , -1);

        return solve(nums , 0 , 0 , target, dp, S);
    }

    public int solve(int[] nums, int i, int currSum, int target , int[][] dp , int S){
        if(i >= nums.length){
            if(currSum == target) return 1;
            else return 0;
        }
        
        if(dp[i][currSum + S] != -1) return dp[i][currSum + S];

        int plus = solve(nums, i+1, currSum + nums[i] , target , dp, S);
        int minus = solve(nums, i+1, currSum - nums[i] , target , dp, S);
        
        return dp[i][currSum + S] = plus + minus;
    }
}