class Solution {
    public int regionsBySlashes(String[] grid) {
        int n = grid.length, m = grid[0].length();
        int[][] matrix = new int[n*3][m*3];
        int regions = 0;
        for(int i=0 ; i<n; i++){
            for(int j=0 ; j<m; j++){
                if(grid[i].charAt(j) == '/'){
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3] = 1;
                }else if(grid[i].charAt(j) == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3 + 2] = 1;  
                }
            }
        }
        for(int i=0 ; i<matrix.length; i++){
            for(int j=0 ; j<matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    numRegions(matrix , i , j);
                    regions++;
                }
            }
        }
        return regions;
    }
    public void numRegions(int[][] matrix, int i, int j){
        if(i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || matrix[i][j] == 1) return;

        matrix[i][j] = 1;

        numRegions(matrix, i+1 , j);
        numRegions(matrix, i , j+1);
        numRegions(matrix, i-1 , j);
        numRegions(matrix, i , j-1);

    }
}