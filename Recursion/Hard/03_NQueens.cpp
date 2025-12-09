class Solution {
public:
    bool isSafe(int r, int c, vector<string>& board, int n){
        int row = r, col = c;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q') return false;
            r--; c--;
        }
        row = r, col = c;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            c--;
        }
        row = r, col = c;
        while(row < n and col >= 0){
            if(board[row][col]=='Q') return false;
            r++; c--;
        }
        return true;
    }
    void solve(int c, vector<string>& board, vector<vector<string>>& ans, int n){
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int r=0; r<n; r++){
            if(isSafe(r, c, board, n)){
                board[r][c] = 'Q';
                solve(c+1, board, ans, n);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        solve(0, board, ans, n);
        return ans;
    }
};