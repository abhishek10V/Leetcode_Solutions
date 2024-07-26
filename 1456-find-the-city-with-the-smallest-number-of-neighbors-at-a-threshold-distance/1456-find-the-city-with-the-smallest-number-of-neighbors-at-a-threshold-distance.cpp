class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
        vector<vector<int>> SPM(n , vector<int>(n, 1e9 +  7));
        for(int i=0 ; i<n ; i++) SPM[i][i] = 0;

        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            SPM[u][v] = w;
            SPM[v][u] = w;
        }
         
        floydWarshall(n , SPM);

        return findResultCity(n , SPM ,dis);
    }
    void floydWarshall(int n ,  vector<vector<int>>& SPM){
        for(int via = 0 ; via<n; via++){
            for(int i=0 ; i<n; i++){
                for(int j=0  ;j<n; j++){
                    SPM[i][j] = min(SPM[i][j] , SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }
    int findResultCity(int n , vector<vector<int>>& SPM , int d){
        int res = -1;
        int least = INT_MAX;

        for(int i=0 ; i<n ; i++){
            int count = 0;
            for(int j=0 ; j<n ; j++){
                if(d >= SPM[i][j] && i != j) count++;
            }
            if(count <= least){
                least = count;
                res = i;
            }
        }
        return res;
    }
};