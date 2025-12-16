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
};

// calculate nse and pse, area = arr[i]*(nse[i]-pse[i]-1);