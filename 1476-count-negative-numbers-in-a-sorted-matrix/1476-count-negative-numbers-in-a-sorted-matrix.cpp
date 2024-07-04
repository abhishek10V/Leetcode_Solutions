class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negCount = 0;
        for(auto & row : grid){
          int index = upper_bound(row.begin(), row.end(), 0,greater<int>()) - row.begin();
          negCount += grid[0].size() - index;
        }
        return negCount;
    }
};