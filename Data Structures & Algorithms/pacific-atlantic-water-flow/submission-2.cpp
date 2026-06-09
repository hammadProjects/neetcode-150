class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> pac(ROWS, vector<int>(COLS, 0));      
        vector<vector<int>> atl(ROWS, vector<int>(COLS, 0));
        
        for(int c = 0; c < COLS; c++)
            dfs(0, c, heights, pac);

        for(int r = 1; r < ROWS; r++)
            dfs(r, 0, heights, pac);

        for(int c = 0; c < COLS; c++)
            dfs(ROWS - 1, c, heights, atl);

        for(int r = 0; r < ROWS; r++)
            dfs(r, COLS - 1, heights, atl);
        
        vector<vector<int>> res;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

private:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& vis) {
        if(vis[r][c]) return;
        vis[r][c] = 1;
    
        for(auto& d: dir) {
            int row = r + d[0];
            int col = c + d[1];

            if(row < 0 || col < 0 || row == ROWS || col == COLS)
                continue;

            if(heights[r][c] > heights[row][col] || vis[row][col])
                continue;

            dfs(row, col, heights, vis);
        }
    }
};