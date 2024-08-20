class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[][][] dp = new int[2][101][101];
        for(int[][] row : dp){
            for(int[] col : row) Arrays.fill(col , -1);
        }

        return solve(piles , 1 , 0 , 1, n, dp);
    }
    public int solve(int[] piles , int person , int i , int M , int n , int[][][] dp){
        if(i >= n) return 0;
        
        if(dp[person][i][M] != -1) return dp[person][i][M];
        int res = (person == 1) ? -1 : Integer.MAX_VALUE;
        int stones = 0;

        for(int x = 1 ; x <= Math.min(2*M, (n - i)) ; x++){
            stones += piles[i + x - 1];

            if(person == 1){ //Alice Turn
                res = Math.max(res , stones + solve(piles , 0 , i + x , Math.max(M , x) , n , dp));
            }else{ // BOB tURN
                res = Math.min(res , solve(piles , 1 , i+x , Math.max(M , x), n , dp));
            }
        }

        return dp[person][i][M] = res;
    }
}