class Solution {
    int[][] dir = {{1,0} , {0,1}, {-1,0}, {0,-1}};

    public int longestIncreasingPath(int[][] matrix) {
        if(matrix == null || matrix.length == 0) return 0;
        int n = matrix.length, m = matrix[0].length;
        int longestPath = 0;
        int[][] dp = new int[n][m];

        for(int i=0; i<n; i++){
            for(int j=0 ; j<m; j++){
                int path = dfs(matrix , n, m, i , j, dp);
                longestPath = Math.max(longestPath , path); 
            }
        }
        return longestPath;
    }
    public int dfs(int[][] mat , int n , int  m , int i , int j, int[][] dp){
        if(dp[i][j] > 0) return dp[i][j];
        int max = 0;

        for(int[] d : dir){
            int x = i + d[0] , y = j + d[1];
            if(x >= 0 && y >= 0 && x < n && y < m && mat[x][y] > mat[i][j]){
                max = Math.max(max , dfs(mat , n , m , x , y , dp));
            }
        }
        return dp[i][j] = max + 1;
    }
}