class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& edges , int n){
       unordered_map<int , vector<int>> mp;
       vector<int> indegree(n+1 , 0);

       for(vector<int> & e : edges){
        int u = e[0] , v = e[1];
        mp[u].push_back(v);
        indegree[v]++;
       }

       queue<int> q;
       int count = 0;
       for(int i=1 ; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            count++;
        }
       }
      vector<int> order;

      while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int & v : mp[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
                count++;
            }
        }
      }

      if(count != n) return {};

      return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        vector<int> topoRow = topoSort(rowC, k);
        vector<int> topoCol = topoSort(colC, k);

        if(topoRow.empty() || topoCol.empty()) return {};

        vector<vector<int>> res(k , vector<int>(k , 0));

        for(int i=0 ; i<k; i++){
            for(int j=0 ; j<k ; j++){
                if(topoRow[i] == topoCol[j]) res[i][j] = topoRow[i];
            }
        }
        return res;
    }
};