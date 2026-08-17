class Solution {
    vector<vector<int>> memo;
public:
    int dfs(int r, int c, int rows, int cols) {
        if(r == rows || c == cols) return 0;
        if(r == (rows - 1) && c == (cols - 1)) return 1;
        if(memo[r][c] != -1) return memo[r][c];

        return memo[r][c] = dfs(r, c + 1, rows, cols) + dfs(r + 1, c, rows, cols);
    }

    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        return dfs(0, 0, m, n);
    }
};
