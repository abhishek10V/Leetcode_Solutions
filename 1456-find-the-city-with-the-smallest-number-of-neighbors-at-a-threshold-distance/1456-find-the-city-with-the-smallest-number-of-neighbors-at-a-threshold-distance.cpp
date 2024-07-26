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
         
        for(int i=0 ; i<n ; i++){
            bellman(n , edges , SPM[i] , i);
        }
        return findResultCity(n , SPM ,dis);
    }
    void bellman(int n , vector<vector<int>>& edges, vector<int>& res, int s){
        fill(res.begin() , res.end() , 1e9+7);
        res[s] = 0;

        for(int i=1 ; i<n ; i++){
            for(auto & e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if(res[u] != 1e9+7 && res[u] + w < res[v]) res[v] = res[u] + w;
                if(res[v] != 1e9+7 && res[v] + w < res[u]) res[u] = res[v] + w;
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