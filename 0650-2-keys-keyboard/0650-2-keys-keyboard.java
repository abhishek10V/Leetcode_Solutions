class Solution {
    public int minSteps(int n) {
        if(n==1) return 0;
        int[][] dp = new int[1001][1001];
        for(int[] row : dp) Arrays.fill(row, -1);

        return 1 + solve(1,1,n,dp);
    }
    public int solve(int currA , int clipA , int n , int[][] dp){
        if(currA == n) return 0;

        if(currA > n) return 100000;
        if(dp[currA][clipA] != -1) return dp[currA][clipA];

        int copyAllPaste = 1+1+ solve(currA + currA , currA , n , dp);
        int paste = 1 + solve(currA + clipA , clipA , n , dp);

        return dp[currA][clipA] = Math.min(copyAllPaste , paste);
    }
}