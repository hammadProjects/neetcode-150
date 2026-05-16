class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for(int i = 0; i < n; i++) {
            pair<int, int> indices1 = {i, 0};
            pair<int, int> indices2 = {n - 1, n - 1 - i};

            while(indices1 != indices2) {
                swap(
                    matrix[indices1.first][indices1.second],
                    matrix[indices2.first][indices2.second]
                );

                indices1.second += 1;
                indices2.first  -= 1;
            }
        }
    }
};