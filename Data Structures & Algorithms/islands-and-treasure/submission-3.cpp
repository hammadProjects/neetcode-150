class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> directions = {{-1,0}, {1,0},
                                          {0,-1}, {0,1}};

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto& dir: directions) {
                int r = row + dir[0];
                int c = col + dir[1];

                if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};