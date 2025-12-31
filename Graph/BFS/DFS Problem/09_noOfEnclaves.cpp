class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0) return 0;
        int m = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 1) q.push({i, 0});
            if (board[i][m - 1] == 1) q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 1) q.push({0, j});
            if (board[n - 1][j] == 1) q.push({n - 1, j});
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (board[x][y] != 1) continue;
            board[x][y] = 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    board[nx][ny] == 1) {
                    q.push({nx, ny});
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};


// Count land cells (1) that cannot reach the boundary by moving up/down/left/right.