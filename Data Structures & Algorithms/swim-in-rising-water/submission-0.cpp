class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxi = grid[0][0];
        vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                          {0, -1}, {0, 1}};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;

        while(!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            maxi = max(maxi, grid[r][c]);
            grid[r][c] = -1;

            if(r == ROWS - 1 && c == COLS - 1) return maxi;

            for(auto& d: directions) {
                int row = r + d[0];
                int col = c + d[1];
                if(row < 0 || col < 0
                 || row > ROWS - 1 
                 || col > COLS - 1 || grid[row][col] == -1) continue;

                 pq.push({grid[row][col], {row, col}});
            }
        }

        return maxi;
    }
};