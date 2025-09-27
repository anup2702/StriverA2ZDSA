class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, top = 0, right = m-1, buttom = n-1;
        vector<int> ans;
        while(left<=right && top<=buttom){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=buttom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<=buttom){
                for(int i=right; i>=left;i--){
                    ans.push_back(matrix[buttom][i]);
                }
                buttom--;
            }
            if(left<=right){
                for(int i=buttom; i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};