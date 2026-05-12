class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = (n * m) - 1;
        while(l <= r) {
            int mid = ((r - l) / 2) + l;
            int row = mid / m;
            int col = mid % m;

            int curr = matrix[row][col];
            if(curr == target) return true;
            else if(curr > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};