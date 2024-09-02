class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
         int n = h.size() , m = h[0].size();
         
         if(n < 1) return {{}};
        vector<vector<int>> res;
        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));

       
        for(int i=0 ; i<m; i++){
            dfs(h , 0 , i , INT_MIN , p);
            dfs(h , n-1 , i , INT_MIN , a);
        }
        for(int i=0 ; i<n; i++){
            dfs(h , i , 0 , INT_MIN , p);
            dfs(h , i , m-1 , INT_MIN , a);
        }

        for(int i=0 ; i<n; i++){
            for(int j=0 ;j<m; j++){
                if(p[i][j] == 1 && a[i][j] == 1) res.push_back({i , j});
            }
        }

        return res;
    }
    void dfs(vector<vector<int>>& h, int i , int j ,int prev, vector<vector<int>>& ocean){
        if(i < 0 || j < 0 || i >= h.size() || j >= h[0].size()) return;
        
        if(ocean[i][j] == 1) return;

        if(h[i][j] < prev) return;

        ocean[i][j] = 1;

        dfs(h , i+1 , j , h[i][j] , ocean);
        dfs(h , i-1 , j , h[i][j] , ocean);
        dfs(h , i , j+1 , h[i][j] , ocean);
        dfs(h , i , j-1 , h[i][j] , ocean);

    }
   
};