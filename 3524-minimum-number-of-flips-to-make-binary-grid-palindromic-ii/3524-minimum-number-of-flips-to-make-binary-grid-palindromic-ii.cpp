class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        for(int i=0 ; i<n/2; ++i){
            for(int j=0 ; j<m/2; ++j){
                  long x =  grid[i][j];
                   x += grid[n -i - 1][j];
                   x +=  grid[i][m - j - 1];
                   x +=  grid[n-i-1][m-j-1];

                ans += min(x , 4 - x);
            }
        }
        int possible = 0, count = 0;

        if(n%2 != 0){
            for(int j=0; j<m/2; ++j){
                if(grid[n/2][j] != grid[n/2][m - j - 1]){
                    ans++;
                    count++;
                }
                if((grid[n/2][j] == grid[n/2][m - j - 1]) && grid[n/2][j] == 1) possible++;
            }
        }
         if(m%2 != 0){
            for(int j=0; j<n/2; ++j){
                if(grid[j][m/2] != grid[n - j - 1][m/2]){
                    ans++;
                    count++;
                }else{
                    if((grid[j][m/2] == grid[n - j - 1][m/2]) && grid[j][m/2] == 1) possible++;
                }
            }
        }
        if(possible%2 == 1 && count == 0) ans += 2;
        if(n%2 != 0 && m%2 != 0 && grid[n/2][m/2] == 1) ans++;
        

        return ans;
    }
};