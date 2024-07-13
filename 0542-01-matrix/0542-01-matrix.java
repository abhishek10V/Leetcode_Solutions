class Solution {
    int m , n;
    int[][] dir = {{0,1} , {0, -1}, {1,0}, {-1, 0}};

    public int[][] updateMatrix(int[][] mat) {
       m = mat.length;
       n = mat[0].length;
       int[][] res = new int[m][n];
       Queue<int[]> q = new LinkedList<>();

       for(int i=0  ;i<m; i++){
        for(int j=0 ; j<n; j++){
            if(mat[i][j] == 0){
                res[i][j] = 0;
                q.offer(new int[]{i,j});
            }
            else res[i][j] = -1;
        }
       } 

       while(!q.isEmpty()){
          int[] cell = q.poll();
          int i=  cell[0] , j= cell[1];

          for(int[] d : dir){
             int new_i = i + d[0];
             int new_j = j + d[1];

             if(new_i>=0 && new_i < m && new_j >=0 && new_j < n && res[new_i][new_j] == -1){
                res[new_i][new_j] = res[i][j] + 1;
                q.offer(new int[] {new_i , new_j});
             }
          }
       } 
       return res;  
    }
}