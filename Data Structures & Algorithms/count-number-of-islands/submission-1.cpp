class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0},
                                {0, -1}, {0, 1}};
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(!vis[r][c] && grid[r][c] == '1') {
                    dfs(r, c, grid, vis);
                    islands++;
                }
            }
        }

        return islands;
    }

private:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        for(auto& d: dir) {
            int row = r + d[0];
            int col = c + d[1];

            if(row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1)
                continue;

            if(vis[row][col])
                continue;

            if(grid[row][col] == '0')
                continue;

            dfs(row, col, grid, vis);
        }
    }
};