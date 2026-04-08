class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        // row
        for(int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for(int j = 0; j < 9; j++) {
                char curr = board[i][j];
                if(curr == '.') continue;

                if(seen.count(curr)) return false;
                seen.insert(curr);
            }
        }

        // col
        for(int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for(int j = 0; j < 9; j++) {
                char curr = board[j][i];
                if(curr == '.') continue;

                if(seen.count(curr)) return false;
                seen.insert(curr);
            }
        }

        // square
        for(int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    int row = (i / 3) * 3 + j;
                    int col = (i % 3) * 3 + k;
                    char curr = board[row][col];
                    if(curr == '.') continue;

                    if(seen.count(curr)) return false;
                    seen.insert(curr);
                }
            }
        }

        return true;
    }
};
