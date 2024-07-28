class Solution {
public:
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int , vector<int>> adj;
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n+1 , INT_MAX);
        vector<int> d2(n+1 , INT_MAX);
        
        priority_queue<pair<int , int> , vector<pair<int , int>>, greater<pair<int , int>>> pq;
        pq.push({0 , 1});
        d1[0] = 0;

        while(!pq.empty()){
            auto [timepassed , node] = pq.top();
            pq.pop();

            if(node == n && d2[n] != INT_MAX) return d2[n];

            int div = timepassed/change;

            if(div%2 != 0){
                timepassed = change * (div + 1);
            }

            for(auto & ngbr : adj[node]){
                if(d1[ngbr] > timepassed + time){
                    d2[ngbr] = d1[ngbr];
                    d1[ngbr] = timepassed + time;
                    pq.push({timepassed + time , ngbr});
                }else if(d2[ngbr] > timepassed + time && d1[ngbr] != timepassed + time){
                    d2[ngbr] = timepassed + time;
                    pq.push({timepassed + time , ngbr});
                }
            }
        }
        return -1;
    }
};