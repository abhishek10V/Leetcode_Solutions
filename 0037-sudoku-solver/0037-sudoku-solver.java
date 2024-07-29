class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }

    public boolean solve(char[][] b) {
        int n = b.length;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (b[row][col] == '.') {
                    for (char i = '1'; i <= '9'; i++) {
                        if (isSafe(b, row, col, i)) {
                            b[row][col] = i;
                            boolean next = solve(b);
                            if (next)
                                return true;
                            else
                                b[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isSafe(char[][] b , int row, int col, char val){
         for(int i=0 ; i<b.length; i++){
            if(b[i][col] == val) return false;
        
            if(b[row][i] == val) return false;
         
            if(b[(3*(row / 3)) + (i / 3)][3*(col/3) + (i%3)] == val) return false;
        }

        return true;
    }
}