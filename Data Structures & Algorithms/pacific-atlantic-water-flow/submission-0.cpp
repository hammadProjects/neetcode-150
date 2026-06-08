class Solution {
public:
    int ROWS, COLS;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<int>> pac(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> atl(ROWS, vector<int>(COLS, 0));

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // Pacific
        for (int c = 0; c < COLS; c++)
            dfs(0, c, pac, heights, dir);
        for (int r = 0; r < ROWS; r++)
            dfs(r, 0, pac, heights, dir);

        // Atlantic
        for (int c = 0; c < COLS; c++)
            dfs(ROWS - 1, c, atl, heights, dir);
        for (int r = 0; r < ROWS; r++)
            dfs(r, COLS - 1, atl, heights, dir);

        vector<vector<int>> res;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c])
                    res.push_back({r, c});
            }
        }

        return res;
    }

private:
    void dfs(int r, int c,
             vector<vector<int>>& vis,
             vector<vector<int>>& heights,
             vector<vector<int>>& dir) {

        if (vis[r][c]) return;
        vis[r][c] = 1;

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS)
                continue;

            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, vis, heights, dir);
        }
    }
};