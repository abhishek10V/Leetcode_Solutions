class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        boolean[] visited = new boolean[n];
        int grps = 0;

        for(int i=0; i<n ; i++){
            if(visited[i] == true) continue;

            dfs(stones , visited, i , n);
            grps++;
        }

        return n - grps;
    }
    public void dfs(int[][] stones , boolean[] visited , int index ,int n){
        visited[index] = true;
        for(int i=0 ; i<n ; i++){
            int r = stones[index][0];
            int c = stones[index][1];
            if(visited[i] == false && (stones[i][0] == r || stones[i][1] == c)){
                dfs(stones , visited,i , n);
            }
        }
    }
}