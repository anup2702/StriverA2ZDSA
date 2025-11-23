// i, j -> j, n-i-1 clockwise

// transpose + reverse each row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // n * n/2
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // n * n/2
        for(int i =0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};