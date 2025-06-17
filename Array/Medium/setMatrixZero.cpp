class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // col[m] = matrix[0][..] row[n] = matrix[..][0]
        int col1 = 1; // Keep track of first el of col
        int n = matrix.size(), m = matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    (j != 0) ? matrix[0][j] = 0 : col1 = 0;
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0){ // mark 1st row 
            for(int j=1; j<m; j++) matrix[0][j] = 0;
        }

        if(col1 == 0){ // then 1st col
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        }


    }
};