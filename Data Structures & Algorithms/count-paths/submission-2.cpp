class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        memo[m - 1][n - 1] = 1;

        for(int r = m - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--) {
                memo[r][c] += memo[r + 1][c] + memo[r][c + 1];
            }
        }

        return memo[0][0];
    }
};