class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int sub = 0;
        for(int i= 0 ; i<n ; i++){
            for(int j=0 ; j<m; j++){
               if(grid2[i][j] == 1 && dfs(grid2 , grid1, i , j , m , n)){
                  sub++;
               }
            }
        }
        return sub;
    }
    bool dfs(vector<vector<int>>& g2 , vector<vector<int>>& g1 , int i , int j , int m , int n){
        if(i < 0 || i >= n || j < 0 || j >= m || g2[i][j] != 1) return true;

        
        g2[i][j] = -1;
        
        bool res = (g1[i][j] == 1);

        res = res & dfs(g2 , g1 , i+1 , j , m, n);
        res = res & dfs(g2, g1 , i-1 , j , m, n);
        res = res & dfs(g2 , g1 , i , j+1 , m, n);
        res = res & dfs(g2 , g1 , i , j-1 , m, n);

        return res;

    }
};