class Solution {
public:
    int countArea(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int m, int n) {
        if(i >= m || j >= n || i < 0 || j < 0 || vis[i][j] || grid[i][j] == 0) return 0;
        vis[i][j] = true;
        return 1 +countArea(grid, vis, i+1, j, m, n)+
        countArea(grid, vis, i-1, j, m, n)+
        countArea(grid, vis, i, j+1, m, n)+
        countArea(grid, vis, i, j-1, m, n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    max_area = max(countArea(grid, vis, i, j, m, n), max_area);
                }
            }
        }

        return max_area;
    }
};