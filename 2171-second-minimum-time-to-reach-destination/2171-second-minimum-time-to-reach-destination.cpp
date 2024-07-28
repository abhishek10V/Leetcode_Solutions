class Solution {
public:
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
         vector<vector<int>> adj(n+1);
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n+1 , INT_MAX);
        vector<int> d2(n+1 , INT_MAX);
        
        queue<pair<int , int>> q;
        q.push({1 , 1});
        d1[1] = 0;

        while(!q.empty()){
            auto [node , freq] = q.front();
            q.pop();
            
            int timepassed = (freq == 1) ? d1[node] : d2[node];

            if(node == n && d2[n] != INT_MAX) return d2[n];

            int div = timepassed/change;

            if(div%2 != 0){
                timepassed = change * (div + 1);
            }

            for(auto & ngbr : adj[node]){
               if(d1[ngbr] == INT_MAX){
                  d1[ngbr] = timepassed + time;
                  q.push({ngbr , 1});
               }else if(d2[ngbr] == INT_MAX && d1[ngbr] != timepassed + time){
                  d2[ngbr] = timepassed + time;
                  q.push({ngbr , 2});
               }
            }
        }
        return -1;
    }
};