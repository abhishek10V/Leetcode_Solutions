class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currShortestPath = djkstra(edges , n, source , destination);
        if(currShortestPath < target) return {};

        bool matched = (currShortestPath == target);

        for(auto & e : edges){
            if(e[2] == -1){
                e[2] = (matched == true) ? 2e9 : 1;
                if(matched != true){
                    long long newShortestPath = djkstra(edges , n , source , destination);
                    if(newShortestPath <= target){
                        matched = true;
                        e[2] += target - newShortestPath;
                    }
                }
            }
        }
        if(matched == false) return {};

        return edges;
    }
    long long djkstra(vector<vector<int>>& edges , int n , int s , int d){
        unordered_map<long long , vector<pair<long long, long long>>> adj;

        for(auto & e : edges){
            if(e[2] != -1){
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                adj[u].push_back({v , wt});
                adj[v].push_back({u , wt});

            }
        }
        priority_queue<pair<long long, long long> , vector<pair<long long, long long>> , greater<pair<long long, long long>>> pq;
        vector<long long> res(n , INT_MAX);
        vector<bool> visited(n , false);

        res[s] = 0;
        pq.push({0 , s});

        while(!pq.empty()) {
            long long currDist = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            if(visited[currNode] == true) {
                continue;
            }
            visited[currNode] = true;

            for(auto&[nbr, wt] : adj[currNode]) {
                if(res[nbr] > currDist + wt) {
                    res[nbr] = currDist + wt;
                    pq.push({res[nbr], nbr});
                }
            }
        }

        return res[d];
    }
};