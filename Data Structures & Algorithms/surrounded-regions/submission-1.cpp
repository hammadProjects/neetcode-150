class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int, int>> q;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1) {
                    if(board[r][c] == 'O') {
                        q.push({r, c});
                    }
                }
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