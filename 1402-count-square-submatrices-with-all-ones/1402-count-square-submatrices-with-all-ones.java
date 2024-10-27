class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[][] dp = new int[m+1][n+1];
        int res = 0;
        
        for(int[] row : dp) Arrays.fill(row , -1);

        for(int i=0 ; i<m; i++){
            for(int j=0 ; j<n ; j++){
               res += solve(i , j , matrix , dp);
            }
        }
        return res;
    }
    public int solve(int i , int j , int[][] matrix, int[][] dp){
        if(i >= matrix.length || j >= matrix[0].length) return 0;

        if(matrix[i][j] == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i , j+1 , matrix, dp);
        int left = solve(i+1 , j , matrix, dp);
        int diagonal = solve(i+1 , j+1 , matrix, dp);
        
        return dp[i][j] = 1 + Math.min(right , Math.min(left , diagonal));
    }
}