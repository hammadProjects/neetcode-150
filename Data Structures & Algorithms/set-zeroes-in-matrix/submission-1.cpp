class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> rows;
        unordered_map<int, bool> cols;
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(rows.count(i) || cols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};