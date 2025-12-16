class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int l = 0, h = n-1;
        while(l<=h){
            int m = (l+h)/2;
            int col = 0; // column index of the maximum element in row mid
            for(int i=1; i< mat[0].size(); i++){
                if(mat[m][i] > mat[m][col]) col = i;
            }

            int up = (m > 0)? mat[m-1][col] : -1;
            int down = (m < n -1)? mat[m+1][col]: -1;

            if(mat[m][col] > up and mat[m][col] > down) return {m, col};
            else if(down > mat[m][col]) l = m + 1;
            else h = m - 1;
        }
        return {-1,-1};
    }
};