class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n = rowSum.length , m = colSum.length;
        int[][] res = new int[n][m];
    
        int i = 0 , j = 0;

        while(i < n && j < m){
            int sum = Math.min(rowSum[i] , colSum[j]);
            res[i][j] = sum;
            rowSum[i] -= sum;
            colSum[j] -= sum;
            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }

        return res;
    }
}