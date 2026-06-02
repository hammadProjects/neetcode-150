class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int, int>> q;
        for(int c = 0; c < COLS; c++) {
            if(board[0][c] == 'O') {
                q.push({0, c});
            }
        }

        for(int r = 1; r < ROWS; r++) {
            if(board[r][0] == 'O') {
                q.push({r, 0});
            }
        }

        for(int c = 1; c < COLS; c++) {
            if(board[ROWS - 1][c] == 'O') {
                q.push({ROWS - 1, c});
            }
        }

        for(int r = 1; r < ROWS; r++) {
            if(board[r][COLS - 1] == 'O') {
                q.push({r, COLS - 1});
            }
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto& d:dir) {
                int row = r + d[0];
                int col = c + d[1];

                if(row < 0 || col < 0 || row >= ROWS || col >= COLS || board[row][col] == 'X' || board[row][col] == 'S') {
                    continue;
                }

                q.push({row,col});
            }

            board[r][c] = 'S';
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                    continue;
                }

                if(board[r][c] == 'S') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};