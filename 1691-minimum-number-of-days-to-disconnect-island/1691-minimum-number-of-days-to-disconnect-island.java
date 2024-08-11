class Solution {
    public int minDays(int[][] grid) {
        int numIslands = helper(grid);
 
        if(numIslands > 1 || numIslands == 0) return 0;

        else{
            
        for(int i=0 ; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    numIslands = helper(grid);

                    if(numIslands > 1 || numIslands == 0) return 1;

                    grid[i][j] = 1;
                }
            }
        }
        }
        
        return 2;
    }
    public int helper(int[][] grid){
        int islands = 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];

        for(int i=0 ; i<grid.length; i++){
            for(int j=0 ; j<grid[0].length; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    findIsland(grid , i , j , visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    public void findIsland(int[][] grid , int i , int j, boolean[][] visited){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || visited[i][j] || grid[i][j] == 0) return;

        visited[i][j] = true;

        findIsland(grid, i+1 , j, visited);
        findIsland(grid, i , j+1, visited);
        findIsland(grid, i-1 , j, visited);
        findIsland(grid, i , j-1, visited);
    
    }
}