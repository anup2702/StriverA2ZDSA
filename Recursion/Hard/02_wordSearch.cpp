class Solution {
public:
    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, -1, +1};
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(idx == word.length()) return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size()) return false;
        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        for(int k=0; k<4; k++){
            int x = i + dx[k], y = j + dy[k];
            if(dfs(board, word, x, y, idx+1)){
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};