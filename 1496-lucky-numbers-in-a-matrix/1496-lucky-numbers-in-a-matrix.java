class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int n = matrix.length , m = matrix[0].length;
        List<Integer> res = new ArrayList<>();

        for(int i=0 ; i<n; i++){
            for(int j=0; j<m; j++){
                if(isRow(matrix[i][j] , matrix, i , m) && isCol(matrix[i][j], matrix , j , n))
                res.add(matrix[i][j]);
            }
        }
        return res;
    }
    public boolean isRow(int ele , int[][] mat, int row , int m){
        for(int j=0 ; j<m ; j++){
            if(mat[row][j] < ele) return false;
        }
        return true;
    }
    public boolean isCol(int ele , int[][] mat, int col , int n){
        for(int i=0 ; i<n ; i++){
            if(mat[i][col] > ele) return false;
        }
        return true;
    }
}