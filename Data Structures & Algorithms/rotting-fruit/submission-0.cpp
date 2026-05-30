class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) fresh += 1;
                if(grid[i][j] == 2) {
                    pair p = {i, j};
                    q.push(p);
                }
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        while(fresh > 0 && !q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                pair p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for(int d = 0; d < 4; d++) {
                    int row = r + dir[d].first;
                    int col = c + dir[d].second;
                    if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1) {
                        fresh -= 1;
                        grid[row][col] = 2;
                        q.push({row, col});
                    }
                }

            }
            time++;
        }

        return fresh == 0 ? time: -1;
    }
};
