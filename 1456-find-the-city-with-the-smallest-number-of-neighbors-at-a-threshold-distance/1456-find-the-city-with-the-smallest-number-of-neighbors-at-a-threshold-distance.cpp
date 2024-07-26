class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
        unordered_map<int , vector<pair<int , int>>> adj;
        vector<vector<int>> SPM(n , vector<int>(n, 1e9 +  7));
        for(int i=0 ; i<n ; i++) SPM[i][i] = 0;

        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
         
        for(int i=0 ; i<n ; i++){
            dijkstra(n , adj , SPM[i] , i);
        }
        return findResultCity(n , SPM ,dis);
    }
    void dijkstra(int n, unordered_map<int , vector<pair<int , int>>>& adj , vector<int>& res, int S){
       priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int, int>>> pq;
       pq.push({0 , S});
       fill(res.begin() , res.end() , INT_MAX);
       res[S] = 0;

       while(!pq.empty()){
         int d = pq.top().first;
         int node = pq.top().second;
         pq.pop();

         for(auto& p : adj[node]){
            int dis = p.second;
            int adjNode = p.first;

            if(d + dis < res[adjNode]){
                res[adjNode] = d + dis;
                pq.push({d + dis , adjNode});
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