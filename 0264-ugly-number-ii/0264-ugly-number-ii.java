class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n+1];

        int i2 = 1; int i3 = 1; int i5 = 1;
        dp[1] = 1;
        for(int i=2 ; i<=n ; i++){
            int i2UNum = dp[i2] * 2;
            int i3UNum = dp[i3] * 3;
            int i5UNum = dp[i5] * 5;

            dp[i] = Math.min(i2UNum, Math.min(i3UNum, i5UNum));
   
            if(dp[i] == i2UNum) i2++;
            if(dp[i] == i3UNum) i3++;
            if(dp[i] == i5UNum) i5++;

        }

        return dp[n];
    }
}