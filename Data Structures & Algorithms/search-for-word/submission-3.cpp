class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(backtrack(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool backtrack(int r, int c, vector<vector<char>>& board, string word, int idx) {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return false;
        }

        if(board[r][c] != word[idx]) return false;
        if(idx == word.size() - 1) {
            return true;
        }

        char temp = board[r][c];
        board[r][c] = '#';
        bool res = backtrack(r, c - 1, board, word, idx + 1) ||
        backtrack(r, c + 1, board, word, idx + 1) ||
        backtrack(r - 1, c, board, word, idx + 1) ||
        backtrack(r + 1, c, board, word, idx + 1);
        board[r][c] = temp;

        return res;
    }
};