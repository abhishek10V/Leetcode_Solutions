class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length , m = grid[0].length;
        if(n < 3 || m < 3) return 0;
        int count = 0;

        for(int i=0 ; i<=n-3; i++){
            for(int j=0 ;j<=m-3; j++){
                if(isMagic(grid , i , j))
                count++;
            }
        }
        return count;
    }
    public boolean isMagic(int[][] g , int r , int c){
        HashSet<Integer> set = new HashSet<>();

        for(int i=0 ; i<3; i++){
            for(int j=0 ; j<3; j++){
                int num = g[r + i][c + j];

                if(num < 1 || num > 9 || set.contains(num)) return false;
                else set.add(num);
            }
        }

        int SUM = g[r][c+1] + g[r][c+2] + g[r][c];

        for(int i=0; i<3; i++){
            if(g[r+i][c+1] + g[r+i][c+2] + g[r+i][c] != SUM) return false;

            if(g[r+1][c+i] + g[r][c+i] + g[r+2][c+i] != SUM) return false;
        }

        if(g[r][c] + g[r+1][c+1] + g[r+2][c+2] != SUM) return false;

        if(g[r][c+2] + g[r+1][c+1] + g[r+2][c] != SUM) return false;

        return true;
    }
}