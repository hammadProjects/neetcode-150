class Solution {
public:
    bool doesExist = false;
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    backtrack(i, j, board, word, 0);
                }

                if(doesExist) return true;
            }
        }

        return false;
    }

private:
    void backtrack(int r, int c, vector<vector<char>>& board, string word, int idx) {
        if(doesExist || r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        if(board[r][c] != word[idx]) return;
        if(idx == word.size() - 1) {
            doesExist = true;
            return;
        }

        char temp = board[r][c];
        board[r][c] = '#';
        backtrack(r, c - 1, board, word, idx + 1);
        backtrack(r, c + 1, board, word, idx + 1);
        backtrack(r - 1, c, board, word, idx + 1);
        backtrack(r + 1, c, board, word, idx + 1);
        board[r][c] = temp;
    }
};