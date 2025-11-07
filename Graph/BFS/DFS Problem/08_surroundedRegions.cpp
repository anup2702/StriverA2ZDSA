class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][m - 1] == 'O') q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[n - 1][j] == 'O') q.push({n - 1, j});
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (board[x][y] != 'O') continue;
            board[x][y] = 'S';
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    board[nx][ny] == 'O') {
                    q.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'S') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
