class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negCount = 0;
        int row = grid.size() - 1, col = 0;

        while(row >=0 && col < grid[0].size()){
            if(grid[row][col] >= 0) col++;
            else{
                negCount += grid[0].size() - col;
                row--;
            }
        }
        return negCount;
    }
};