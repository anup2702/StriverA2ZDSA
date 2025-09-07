vector<int> Solution::prevSmaller(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, -1);
        st.push(arr[0]);
        for(int i=1; i < n; i++){
            while(!st.empty() and st.top() >= arr[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(arr[i]);
        }
        return nse;
}
