class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int max_row = -1;
        int j = m - 1;

        for (int i = 0; i < n; i++) { // row
            while (j >= 0 && arr[i][j] == 1) { // col
                j--;
                max_row = i;
            }
        }

        return max_row;
    }
};