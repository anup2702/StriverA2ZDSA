class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        int row=0, col = m-1;
        // Start from the top-right corner of the matrix
        // and move left or down based on the comparison with target
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;

            else if(matrix[row][col]<target) row++;

            else col--;
            
        }

        return false;
        
    }
};