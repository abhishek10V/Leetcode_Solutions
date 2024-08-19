class Solution {
    public int minSteps(int n) {
        if (n == 1)
            return 0;
        if (n == 2)
            return 2;

        int[] dp = new int[n + 1];

        dp[0] = dp[1] = 0;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            int factor = i / 2;

            while (factor >= 1) {
                if (i % factor == 0) {
                    int stepsToPrintFactorAs = dp[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    dp[i] = stepsToPrintFactorAs + copy + paste;
                    break;
                } else {
                    factor--;
                }
            }
        }
        return dp[n];
    }
}