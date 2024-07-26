class Solution {
    List<List<String>> result;
    public List<List<String>> solveNQueens(int n) {
        result = new ArrayList<>();
        char[][] board = new char[n][n];

        for(char[] row : board) Arrays.fill(row , '.');
        List<int[]> queens = new ArrayList<>();
        dfs(board, 0 , queens);

        return result;
    }
    public void dfs(char[][] board , int r , List<int[]> q){
        if(q.size() == board.length){
            List<String> rows = new ArrayList<>();
            for(char[] row : board){
                rows.add(new String(row));
            }
            result.add(rows);
        }

        for(int c=0 ; c<board.length; c++){
            if(canAddQueens(r , c , q)){
                board[r][c] = 'Q';
                q.add(new int[]{r , c});
                dfs(board , r+1 , q);
                board[r][c] = '.';
                q.remove(q.size() - 1);
            }
        }
    }
    public boolean canAddQueens(int r , int c , List<int[]> q){
        for(int[] qs : q){
            int dx = Math.abs(r - qs[0]);
            int dy = Math.abs(c - qs[1]);

            if(dx == 0 || dy == 0 || dx == dy) return false;
        }
        return true;
    }
}