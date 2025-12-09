class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[r][i] == ch) return false;
            if(board[i][c] == ch) return false;
        }
        int sr = r - r % 3;
        int sc = c - c % 3;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[sr + i][sc + j] == ch) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int r, int c) {
        if(r == 9) return true;
        if(c == 9) return solve(board, r + 1, 0);

        if(board[r][c] != '.') return solve(board, r, c + 1);

        for(char ch = '1'; ch <= '9'; ch++) {
            if(isSafe(board, r, c, ch)) {
                board[r][c] = ch;
                if(solve(board, r, c + 1)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
