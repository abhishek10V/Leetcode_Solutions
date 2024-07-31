class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(1001 , vector<int>(1001 ,-1));

        return solve(0 ,books , shelfWidth ,0, shelfWidth, dp);
    }
    int solve(int i , vector<vector<int>>& books, int remainW, int h, int width, vector<vector<int>>& dp){
        if(i >= books.size()) return h;

        int bookH = books[i][1];
        int bookW = books[i][0];
        int keep = INT_MAX;
        int skip = INT_MAX;

        if(dp[i][remainW] != -1) return dp[i][remainW];

        if(remainW >= bookW){
            keep = solve(i+1, books, remainW - bookW, max(h, bookH), width, dp);
        }

        skip = h + solve(i+1 , books , width - bookW, bookH, width, dp);

        return dp[i][remainW] = min(keep , skip);
    }
};