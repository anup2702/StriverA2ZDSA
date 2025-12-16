class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ar = 0, n = heights.size();
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()] >= heights[i]){
                int el = st.top(); st.pop();
                int nse = i, pse = (st.empty()) ? -1: st.top();
                ar = max(ar, heights[el]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = st.top(); st.pop();
            int nse = n, pse = (st.empty()) ? -1: st.top();
            ar = max(ar, heights[el]*(nse-pse-1));
        }
        return ar;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pSum(n, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum = 0;
                pSum[i][j] = sum;
            }
        }

        int mxArea = 0;
        for(int i=0; i<n; i++){
            mxArea = max(mxArea, largestRectangleArea(pSum[i]));
        }
        return mxArea;
    }
};