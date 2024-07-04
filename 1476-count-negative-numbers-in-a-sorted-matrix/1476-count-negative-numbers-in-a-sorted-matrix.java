class Solution {
    public int countNegatives(int[][] grid) {
       int negCount = 0;
        int row = grid.length - 1, col = 0;

        while(row >=0 && col < grid[0].length){
            if(grid[row][col] >= 0) col++;
            else{
                negCount += grid[0].length - col;
                row--;
            }
        }
        return negCount;
    }
}