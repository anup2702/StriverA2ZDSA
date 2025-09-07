class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        while (top < down) {
            if (mat[top][down]) top++;
            else down--;
        }

        int cel = top;

        for (int i = 0; i < n; i++) {
            if (i == cel) continue;
            if (mat[cel][i] == 1 || mat[i][cel] == 0) {
                return -1;
            }
        }

        return cel;
    }
};
